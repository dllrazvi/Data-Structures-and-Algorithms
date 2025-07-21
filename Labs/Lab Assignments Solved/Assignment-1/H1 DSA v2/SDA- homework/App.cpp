#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"

using namespace std;

void transpose(Matrix& matrix) {
    int rows = matrix.nrLines();
    int cols = matrix.nrColumns();
    Matrix temp(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp.modify(j, i, matrix.element(i, j));
        }
    }

    matrix = temp;
}

int main() {
    testAll();
    testAllExtended();

    Matrix matrix(3, 4);
    matrix.modify(0, 0, 1);
    matrix.modify(0, 1, 2);
    matrix.modify(0, 2, 3);
    matrix.modify(0, 3, 4);
    matrix.modify(1, 0, 5);
    matrix.modify(1, 1, 6);
    matrix.modify(1, 2, 7);
    matrix.modify(1, 3, 8);
    matrix.modify(2, 0, 9);
    matrix.modify(2, 1, 10);
    matrix.modify(2, 2, 11);
    matrix.modify(2, 3, 12);

    //cout << "Original matrix: " << endl;
    //cout<< matrix << endl;

    //transpose(matrix); 

    //cout << "Transposed matrix: " << endl;
    //cout << matrix << endl;

    //cout << "Test End" << endl;
    system("pause");
    return 0;
}
