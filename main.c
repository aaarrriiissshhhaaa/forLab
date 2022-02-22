#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include <memory.h>

long long getScalarProductRowAndCol(matrix m, int indexRow, int indexCol) {
    int elemCol[m.nRows];
    for (int rowNumber = 0; rowNumber < m.nRows; rowNumber++)
        elemCol[rowNumber] = m.values[rowNumber][indexCol];

    long long productRowAndCol = 0;
    for (int colNumber = 0; colNumber < m.nRows; colNumber++)
        productRowAndCol += elemCol[colNumber] * m.values[indexRow][colNumber];

    return productRowAndCol;
}

long long getSpecialScalarProduct(matrix m) {
    position maxElem = getMaxValuePos(m);
    position minElem = getMinValuePos(m);

    return getScalarProductRowAndCol(m, maxElem.rowIndex, minElem.colIndex);
}

void test_getSpecialScalarProduct_classicSquarMatrix() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            }, 3, 3
    );

    assert(getSpecialScalarProduct(c) == 7 * 1 + 4 * 8 + 9 * 7);

    freeMemMatrix(c);
}

void test_getSpecialScalarProduct_SquarMatrixNegativElemnt() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    -1, -2, -3,
                    -4, -5, -6,
                    -7, -8, -9
            }, 3, 3
    );

    assert(getSpecialScalarProduct(c) == -3 * -1 +  -6 * -2 + -9 * -3);

    freeMemMatrix(c);
}

void test_getSpecialScalarProduct_minAndMaxInOneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 9, 3,
                    4, 5, 6,
                    7, 8, 2
            }, 3, 3
    );

    assert(getSpecialScalarProduct(m) == 1 * 1 + 4 * 9 + 7 * 3);

    freeMemMatrix(m);
}


void test_getSpecialScalarProduct() {
    test_getSpecialScalarProduct_classicSquarMatrix();
    test_getSpecialScalarProduct_SquarMatrixNegativElemnt();
    test_getSpecialScalarProduct_minAndMaxInOneRow();
}


int main() {
    test_getSpecialScalarProduct();

    return 0;
}