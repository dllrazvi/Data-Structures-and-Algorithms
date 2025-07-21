#include <assert.h>
#include "Matrix.h"

#include <iostream>
using namespace std;

void testAll() {
    // create a 4x4 matrix
    Matrix m(4, 4);

    // test the nrLines and nrColumns functions
    assert(m.nrLines() == 4);
    assert(m.nrColumns() == 4);

    // test the modify and element functions
    m.modify(1, 1, 5);
    assert(m.element(1, 1) == 5);
    TElem old = m.modify(1, 1, 6);
    assert(m.element(1, 1) == 6);
    assert(old == 5);

    // test some other positions to make sure they return the null element
    assert(m.element(1, 2) == NULL_TELEM);
    assert(m.element(2, 1) == NULL_TELEM);
}

int main2() {
    testAll();
    cout << "All tests passed!\n";
    return 0;
}