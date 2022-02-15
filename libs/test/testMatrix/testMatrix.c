#include "../../data_structures/matrix/matrix.h"

#include "testMatrix.h"
#include <assert.h>

int criteria(int *m, int a) {
    return m[0];
}

void test_swapRowsWithVerificationIndex_extremeRowSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3,
                                              5, 6, 7,
                                              9, 10, 11},
                                     3, 3);
    swapRowsWithVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {9, 10, 11,
                                                  5, 6, 7,
                                                  1, 2, 3},
                                         3, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex_extremeRowNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, 8,
                                              9, 10, 11, 12},
                                     3, 4);
    swapRowsWithVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {9, 10, 11, 12,
                                                  5, 6, 7, 8,
                                                  1, 2, 3, 4},
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex_extremeRowOneColumn() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3},
                                     3, 1);
    swapRowsWithVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {3, 2, 1},
                                         3, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex_centerRowSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, 5,
                                              9, 10, 11, 6,
                                              12, 13, 14, 7},
                                     4, 4);
    swapRowsWithVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 2, 3, 4,
                                                 9, 10, 11, 6,
                                                 5, 6, 7, 5,
                                                 12, 13, 14, 7},
                                         4, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex_centerRowNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3,
                                              5, 6, 7,
                                              9, 10, 11,
                                              12, 13, 14},
                                     4, 3);
    swapRowsWithVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 2, 3,
                                                 9, 10, 11, 5, 6, 7,
                                                 12, 13, 14},
                                         4, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex_centerRowOneColumn() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     4, 1);
    swapRowsWithVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 3, 2, 4},
                                         4, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex_SameRow() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     4, 1);
    swapRowsWithVerificationIndex(c, 1, 1);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 2, 3, 4},
                                         4, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithVerificationIndex() {
    test_swapRowsWithVerificationIndex_extremeRowSquare();
    test_swapRowsWithVerificationIndex_extremeRowNonSquare();
    test_swapRowsWithVerificationIndex_extremeRowOneColumn();

    test_swapRowsWithVerificationIndex_centerRowSquare();
    test_swapRowsWithVerificationIndex_centerRowNonSquare();
    test_swapRowsWithVerificationIndex_centerRowOneColumn();

    test_swapRowsWithVerificationIndex_SameRow();
}

void test_swapRowsWithoutVerificationIndex_extremeRowSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3,
                                              5, 6, 7,
                                              9, 10, 11},
                                     3, 3);
    swapRowsWithoutVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {9, 10, 11,
                                                  5, 6, 7,
                                                  1, 2, 3},
                                         3, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithoutVerificationIndex_extremeRowNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, 8,
                                              9, 10, 11, 12},
                                     3, 4);
    swapRowsWithoutVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {9, 10, 11, 12,
                                                  5, 6, 7, 8,
                                                  1, 2, 3, 4},
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithoutVerificationIndex_extremeRowOneColumn() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3},
                                     3, 1);
    swapRowsWithoutVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {3, 2, 1},
                                         3, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithoutVerificationIndex_centerRowSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, 5,
                                              9, 10, 11, 6,
                                              12, 13, 14, 7},
                                     4, 4);
    swapRowsWithoutVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 2, 3, 4,
                                                 9, 10, 11, 6,
                                                 5, 6, 7, 5,
                                                 12, 13, 14, 7},
                                         4, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithoutVerificationIndex_centerRowNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3,
                                              5, 6, 7,
                                              9, 10, 11,
                                              12, 13, 14},
                                     4, 3);
    swapRowsWithoutVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 2, 3,
                                                 9, 10, 11, 5, 6, 7,
                                                 12, 13, 14},
                                         4, 3);
    assert(areTwoMatricesEqual(c, cTrue));
}

void test_swapRowsWithoutVerificationIndex_centerRowOneColumn() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     4, 1);
    swapRowsWithoutVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 3, 2, 4},
                                         4, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithoutVerificationIndex_SameRow() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     4, 1);
    swapRowsWithoutVerificationIndex(c, 1, 1);
    matrix cTrue = createMatrixFromArray((int[]) {
                                                 1, 2, 3, 4},
                                         4, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapRowsWithoutVerificationIndex() {
    test_swapRowsWithoutVerificationIndex_extremeRowSquare();
    test_swapRowsWithoutVerificationIndex_extremeRowNonSquare();
    test_swapRowsWithoutVerificationIndex_extremeRowOneColumn();

    test_swapRowsWithoutVerificationIndex_centerRowSquare();
    test_swapRowsWithoutVerificationIndex_centerRowNonSquare();
    test_swapRowsWithoutVerificationIndex_centerRowOneColumn();

    test_swapRowsWithoutVerificationIndex_SameRow();
}

void test_swapColumnsWithVerificationIndex_extremeColSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    swapColumnsWithVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {3, 2, 1,
                                                  3, 2, 1,
                                                  3, 2, 1},
                                         3, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex_extremeColNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4},
                                     3, 4);
    swapColumnsWithVerificationIndex(c, 0, 3);
    matrix cTrue = createMatrixFromArray((int[]) {4, 2, 3, 1,
                                                  4, 2, 3, 1,
                                                  4, 2, 3, 1},
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex_extremeColOneRow() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    swapColumnsWithVerificationIndex(c, 0, 3);
    matrix cTrue = createMatrixFromArray((int[]) {4, 2, 3, 1},
                                         1, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex_centerColSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4},
                                     4, 4);
    swapColumnsWithVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                                  1, 3, 2, 4},
                                         4, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex_centerColNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4,},
                                     3, 4);
    swapColumnsWithVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                         },
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex_centerColOneRow() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    swapColumnsWithVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 2, 4},
                                         1, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex_SameCol() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    swapColumnsWithVerificationIndex(c, 1, 1);
    matrix cTrue = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                         1, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithVerificationIndex() {
    test_swapColumnsWithVerificationIndex_extremeColSquare();
    test_swapColumnsWithVerificationIndex_extremeColNonSquare();
    test_swapColumnsWithVerificationIndex_extremeColOneRow();

    test_swapColumnsWithVerificationIndex_centerColSquare();
    test_swapColumnsWithVerificationIndex_centerColNonSquare();
    test_swapColumnsWithVerificationIndex_centerColOneRow();

    test_swapColumnsWithVerificationIndex_SameCol();
}

void test_swapColumnsWithoutVerificationIndex_extremeColSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3,
                                              1, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    swapColumnsWithoutVerificationIndex(c, 0, 2);
    matrix cTrue = createMatrixFromArray((int[]) {3, 2, 1,
                                                  3, 2, 1,
                                                  3, 2, 1},
                                         3, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex_extremeColNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4},
                                     3, 4);
    swapColumnsWithoutVerificationIndex(c, 0, 3);
    matrix cTrue = createMatrixFromArray((int[]) {4, 2, 3, 1,
                                                  4, 2, 3, 1,
                                                  4, 2, 3, 1},
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex_extremeColOneRow() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    swapColumnsWithoutVerificationIndex(c, 0, 3);
    matrix cTrue = createMatrixFromArray((int[]) {4, 2, 3, 1},
                                         1, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex_centerColSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4},
                                     4, 4);
    swapColumnsWithoutVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                                  1, 3, 2, 4},
                                         4, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex_centerColNonSquare() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4,},
                                     3, 4);
    swapColumnsWithoutVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                                  1, 3, 2, 4,
                                         },
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex_centerColOneRow() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    swapColumnsWithoutVerificationIndex(c, 1, 2);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 2, 4},
                                         1, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex_SameCol() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                     1, 4);
    swapColumnsWithoutVerificationIndex(c, 1, 1);
    matrix cTrue = createMatrixFromArray((int[]) {1, 2, 3, 4},
                                         1, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_swapColumnsWithoutVerificationIndex() {
    test_swapColumnsWithoutVerificationIndex_extremeColSquare();
    test_swapColumnsWithoutVerificationIndex_extremeColNonSquare();
    test_swapColumnsWithoutVerificationIndex_extremeColOneRow();

    test_swapColumnsWithoutVerificationIndex_centerColSquare();
    test_swapColumnsWithoutVerificationIndex_centerColNonSquare();
    test_swapColumnsWithoutVerificationIndex_centerColOneRow();

    test_swapColumnsWithoutVerificationIndex_SameCol();
}

void test_insertionSortRowsMatrixByRowCriteria_SquareMatrix() {
    matrix c = createMatrixFromArray((int[]) {9, 1, 1,
                                              3, 2, 2,
                                              1, 3, 3},
                                     3, 3);
    insertionSortRowsMatrixByRowCriteria(c, criteria);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 3,
                                                  3, 2, 2,
                                                  9, 1, 1},
                                         3, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_insertionSortRowsMatrixByRowCriteria_NonSquareMatrix() {
    matrix c = createMatrixFromArray((int[]) {9, 1, 1, 1,
                                              3, 2, 2, 2,
                                              1, 3, 3, 3},
                                     3, 4);
    insertionSortRowsMatrixByRowCriteria(c, criteria);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 3, 3,
                                                  3, 2, 2, 2,
                                                  9, 1, 1, 1},
                                         3, 4);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_insertionSortRowsMatrixByRowCriteria_SquareMatrixOneCol() {
    matrix c = createMatrixFromArray((int[]) {9, 1, 2, 6},
                                     4, 1);
    insertionSortRowsMatrixByRowCriteria(c, criteria);
    matrix cTrue = createMatrixFromArray((int[]) {1, 2, 6, 9},
                                         4, 1);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    test_insertionSortRowsMatrixByRowCriteria_SquareMatrix();
    test_insertionSortRowsMatrixByRowCriteria_NonSquareMatrix();
    test_insertionSortRowsMatrixByRowCriteria_SquareMatrixOneCol();
}

void test_insertionSortColsMatrixByColCriteria_SquareMatrix() {
    matrix c = createMatrixFromArray((int[]) {9, 3, 1,
                                              1, 2, 3,
                                              1, 2, 3},
                                     3, 3);
    insertionSortColsMatrixByColCriteria(c, criteria);
    matrix cTrue = createMatrixFromArray((int[]) {1, 3, 9,
                                                  3, 2, 1,
                                                  3, 2, 1},
                                         3, 3);
    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_insertionSortColsMatrixByColCriteria_NonSquareMatrix() {
    matrix c = createMatrixFromArray((int[]) {9, 1, 2, 6,
                                              1, 2, 3, 4,
                                              1, 2, 3, 4},
                                     3, 4);
    insertionSortColsMatrixByColCriteria(c, criteria);
    matrix cTrue = createMatrixFromArray((int[]) {1, 2, 6, 9,
                                                  2, 3, 4, 1,
                                                  2, 3, 4, 1},
                                         3, 4);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_insertionSortColsMatrixByColCriteria_MatrixOneCol() {
    matrix c = createMatrixFromArray((int[]) {9, 1, 2},
                                     3, 1);
    insertionSortColsMatrixByColCriteria(c, criteria);
    matrix cTrue = createMatrixFromArray((int[]) {9, 1, 2},
                                         3, 1);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_insertionSortColsMatrixByColCriteria() {
    test_insertionSortColsMatrixByColCriteria_SquareMatrix();
    test_insertionSortColsMatrixByColCriteria_NonSquareMatrix();
    test_insertionSortColsMatrixByColCriteria_MatrixOneCol();
}

void test_isSquareMatrix_SquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 10
            },
            3, 3);

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix_NonSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 11,
                    4, 5, 6, 12,
                    7, 8, 10, 13
            },
            3, 4);

    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix_OneElement() {
    matrix m = createMatrixFromArray(
            (int[]) {1},
            1, 1);

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}


void test_isSquareMatrix() {
    test_isSquareMatrix_SquareMatrix();
    test_isSquareMatrix_NonSquareMatrix();
    test_isSquareMatrix_OneElement();
}

void test_areTwoMatricesEqual_TwoMatricesEqual() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);

    assert(areTwoMatricesEqual(c1, c2));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
}

void test_areTwoMatricesEqual_TwoMatricesNonEqual() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 10,
            },
            3, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual_TwoMatricesEqual();
    test_areTwoMatricesEqual_TwoMatricesNonEqual();
}

void test_isEMatrix_eMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_NotEMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 1, 1
            },
            3, 3);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix() {
    test_isEMatrix_eMatrix();
    test_isEMatrix_NotEMatrix();
}

void test_isSymmetricMatrix_SymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 8, 0,
                    8, 1, 8,
                    0, 8, 1
            },
            3, 3);

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NotSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 0, 6,
                    0, 2, 3,
                    6, 4, 1
            },
            3, 3);

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_SymmetricMatrix();
    test_isSymmetricMatrix_NotSymmetricMatrix();
}

void test_transposeSquareMatrix_classicMatrix(){
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3);

    transposeSquareMatrix(c1);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9
            },
            3, 3);

    assert(areTwoMatricesEqual(c1, c2));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix_classicMatrix();
}

void test_getMinValuePos_classicMatrix() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, 8,
                                              9, 10, 11, 12},
                                     3, 4);

    position min = getMinValuePos(c);
    position minTrue = {0, 0};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
}

void test_getMinValuePos_identicalElements(){
    matrix c = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                              1, 1, 1, 1,
                                              1, 1, 1, 1},
                                     3, 4);

    position min = getMinValuePos(c);
    position minTrue = {0, 0};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
}

void test_getMinValuePos_NegativeNumbers(){
    matrix c = createMatrixFromArray((int[]) {-1, -2, -8},
                                     1, 3);

    position min = getMinValuePos(c);
    position minTrue = {0, 2};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
}

void test_getMinValuePos() {
    test_getMinValuePos_classicMatrix();
    test_getMinValuePos_identicalElements();
    test_getMinValuePos_NegativeNumbers();
}

void test_getMaxValuePos_classicMatrix() {
    matrix c = createMatrixFromArray((int[]) {1, 2, 3, 4,
                                              5, 6, 7, -8,
                                              9, 10, 11, 12},
                                     3, 4);

    position max = getMaxValuePos(c);
    position maxTrue = {2, 3};

    assert(max.colIndex == maxTrue.colIndex && max.rowIndex == maxTrue.rowIndex);
}

void test_getMaxValuePos_identicalElements(){
    matrix c = createMatrixFromArray((int[]) {1, 1, 1},
                                     1, 1);

    position max = getMaxValuePos(c);
    position maxTrue = {0, 0};

    assert(max.colIndex == maxTrue.colIndex && max.rowIndex == maxTrue.rowIndex);
}

void test_getMaxValuePos_NegativeNumbers(){
    matrix c = createMatrixFromArray((int[]) {-1, -2, -8},
                                     1, 3);

    position min = getMaxValuePos(c);
    position minTrue = {0, 0};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
}

void test_getMaxValuePos() {
    test_getMaxValuePos_classicMatrix();
    test_getMaxValuePos_identicalElements();
    test_getMaxValuePos_NegativeNumbers();
}

void test_mulMatrices_Square(){
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);

    matrix c3 = mulMatrices(c1, c2);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    30, 36, 42,
                    66, 81, 96,
                    102, 126, 150
            },
            3, 3);

    assert(areTwoMatricesEqual(c3, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
    freeMemMatrix(c3);
    freeMemMatrix(cTrue);
}

void test_mulMatrices_NonSquare(){
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    2, 1,
                    -3, 0,
                    4, -1,
            },
            3, 2);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    5, -1, 6,
                    -3, 0, 7
            },
            2, 3);

    matrix c3 = mulMatrices(c1, c2);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    7, -2, 19,
                    -15, 3, -18,
                    23, -4, 17
            },
            3, 3);

    assert(areTwoMatricesEqual(c3, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
    freeMemMatrix(c3);
    freeMemMatrix(cTrue);
}

void test_mulMatrices_toEMatrix(){
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1,
            },
            3, 3);

    matrix c3 = mulMatrices(c1, c2);

    assert(areTwoMatricesEqual(c3, c1));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
    freeMemMatrix(c3);
}

void test_mulMatrices() {
    test_mulMatrices_Square();
    test_mulMatrices_NonSquare();
    test_mulMatrices_toEMatrix();
}

void testMatrix() {
    test_swapRowsWithVerificationIndex();
    test_swapRowsWithoutVerificationIndex();
    test_swapColumnsWithVerificationIndex();
    test_swapColumnsWithoutVerificationIndex();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
    test_mulMatrices();
}
