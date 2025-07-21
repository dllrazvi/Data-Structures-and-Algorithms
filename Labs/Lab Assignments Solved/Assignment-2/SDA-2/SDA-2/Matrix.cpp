#include "Matrix.h"
#include <exception>

Matrix::Matrix(int nrLines, int nrCols) {
    lines = nrLines;
    columns = nrCols;
    head = nullptr;
}

Matrix::~Matrix() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

int Matrix::nrLines() const {
    return lines;
}

int Matrix::nrColumns() const {
    return columns;
}

TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= lines || j < 0 || j >= columns)
        throw std::exception("Invalid position in matrix!");

    Node* current = head;
    while (current != nullptr) {
        if (current->line == i && current->column == j)
            return current->value;
        current = current->next;
    }

    return NULL_TELEM;
}
//WC - O(n)
//BC - O(1)
//AV - O(n/2) -> O(n)

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= lines || j < 0 || j >= columns)
        throw std::exception("Invalid position in matrix!");

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->line == i && current->column == j) {
            TElem previousValue = current->value;
            current->value = e;
            return previousValue;
        }
        else if (current->line > i || (current->line == i && current->column > j)) {
            // Found the position where the new element should be inserted
            Node* newNode = new Node;
            newNode->line = i;
            newNode->column = j;
            newNode->value = e;

            if (prev == nullptr) {
                // Inserting at the beginning of the DLL
                newNode->prev = nullptr;
                newNode->next = current;
                current->prev = newNode;
                head = newNode;
            }
            else {
                // Inserting in the middle or at the end of the DLL
                newNode->prev = prev;
                newNode->next = current;
                prev->next = newNode;
                current->prev = newNode;
            }

            return NULL_TELEM;
        }

        prev = current;
        current = current->next;
    }

    // Reached the end of the DLL, need to insert at the end
    Node* newNode = new Node;
    newNode->line = i;
    newNode->column = j;
    newNode->value = e;
    newNode->prev = prev;
    newNode->next = nullptr;

    if (prev != nullptr)
        prev->next = newNode;
    else
        head = newNode;

    return NULL_TELEM;
}
//WC - O(n)
//BC - O(1)
//AV - O(n/2) -> O(n)

void Matrix::setElemsOnLine(int line, TElem elem) {
    if (line < 0 || line >= lines)
        throw std::exception("Invalid line in matrix!");

    Node* current = head;
    while (current != nullptr) {
        if (current->line == line)
            current->value = elem;
        current = current->next;
    }
}
//WC - O(n)
//BC - O(1)
//AV - O(n/2) -> O(n)

