#pragma once
#include<vector>

typedef int TElem;
const int NULL_TELEM = 0;
class Matrix {
private:
    int rows;
    int cols;
    std::vector<TElem> values;
    std::vector<int> row_indexes;
    std::vector<int> column_indexes;

public:
    //constructor
    //throws exception if nrLines or nrCols is negative or zero,
   
    Matrix(int nrLines, int nrCols);

    //returns the number of lines
    int nrLines() const;

    //returns the number of columns
    int nrColumns() const;

    //returns the element from line i and column j (indexing starts from 0)
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem element(int i, int j) const;

    //modifies the value from line i and column j
    //returns the previous value from the (i,j) position
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem modify(int i, int j, TElem e);

    //transpose the matrix
    void transpose();
};
