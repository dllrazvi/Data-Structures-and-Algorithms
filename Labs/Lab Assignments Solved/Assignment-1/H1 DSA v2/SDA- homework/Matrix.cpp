#include "Matrix.h"
#include <stdexcept>
#include <iostream>

Matrix::Matrix(int nrLines, int nrCols) {
    this->rows = nrLines;
    this->cols = nrCols;
    this->column_indexes = std::vector<int>(nrCols + 1, 0);
}

int Matrix::nrLines() const {
    return rows;
}

int Matrix::nrColumns() const {
    return cols;
}

//BC- O(n)
//WC - O(m), where m is the number of non-zero elements in the column of the specified index
//AC- 0(logn)
TElem Matrix::element(int i, int j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Invalid position");
    }
    for (int k = column_indexes[j]; k < column_indexes[j + 1]; k++) {
        if (row_indexes[k] == i) {
            return values[k];
        }
    }
    return NULL_TELEM;
}


//Best case: O(1) - If the matrix is a 1x1 matrix or an empty matrix, then there is nothing to transpose and the function can simply return the input matrix.
//Worst case: O(mn) - If the matrix has m rows and n columns, then the transpose function will need to create a new matrix with n rows and m columns, and fill it with the elements of the input matrix.This requires iterating over each element in the input matrix exactly once, which gives a time complexity of O(mn).
//Average case: O(mn) - The average case is the same as the worst case because the function always needs to iterate over every element in the input matrix.
//Theta notation : Θ(mn) - The time complexity is bounded both above and below by a multiple of mn, so we can say that the time complexity is Θ(mn).

void Matrix::transpose() {
    int n = rows * cols;
    std::vector<TElem> new_values(n);
    std::vector<int> new_row_indexes(n);
    std::vector<int> new_column_indexes(cols + 1, 0);

    for (int k = 0; k < n; k++) {
        new_row_indexes[k] = column_indexes[k % cols];
        new_column_indexes[k % cols]++;
        new_values[k] = values[column_indexes[k % cols] + k / cols];
    }

    values = new_values;
    row_indexes = new_row_indexes;
    column_indexes = new_column_indexes;
    std::swap(rows, cols);
}
//O(nnz), where nnz is the number of non-zero elements in the matrix.
/*TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) {
        throw std::out_of_range("Invalid position");
    }
    TElem previous_value = NULL_TELEM;
    bool found = false;
    for (int k = column_indexes[j]; k < column_indexes[j + 1]; k++) {
        if (row_indexes[k] == i) {
            previous_value = values[k];
            values[k] = e;
            found = true;
            break;
        }
    }
    if (!found) {
        values.push_back(e);
        row_indexes.push_back(i);
        for (int k = j + 1; k <= cols; k++) {
            column_indexes[k]++;
        }
    }
    return previous_value;
}*/
    
 
    //O(nnz), where nnz is the number of non-zero elements in the matrix.
TElem Matrix::modify(int i, int j, TElem e) {
    TElem previous_value = NULL_TELEM;
    bool found = false;
    for (int k = column_indexes[j]; k < column_indexes[j + 1]; k++) {
        if (row_indexes[k] == i) {
            previous_value = values[k];
            values[k] = e;
            found = true;
            break;
        }
    }
    if (!found) {
		values.push_back(e);
		row_indexes.push_back(i);
        for (int k = j + 1; k <= cols; k++) {
			column_indexes[k]++;
		}
	}
    return previous_value;
}
            
        

