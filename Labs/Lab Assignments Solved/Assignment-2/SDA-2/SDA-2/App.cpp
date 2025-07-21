#include <iostream>
#include "Matrix.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
using namespace std;
void testSetElemsOnLine() {
    Matrix matrix(3, 3);

    // Set all elements on line 1 to 10
    matrix.setElemsOnLine(1, 10);

    // Verify the values on line 1
    for (int j = 0; j < matrix.nrColumns(); ++j) {
        int value = matrix.element(1, j);
        cout << "Matrix[1][" << j << "] = " << value << endl;
    }
}

int main() {
    // Call the new test function
    testSetElemsOnLine();
    testAll();
    testAllExtended();
    cout << "Test End" << endl;

 

    system("pause");
}

