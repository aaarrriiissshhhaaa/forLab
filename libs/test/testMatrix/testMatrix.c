#include "../../data_structures/matrix/matrix.h"

#include "testMatrix.h"
#include <assert.h>
#include "../../data_structures/5dquestions/questions.h"

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

void test_transposeSquareMatrix_classicMatrix() {
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

void test_getMinValuePos_identicalElements() {
    matrix c = createMatrixFromArray((int[]) {1, 1, 1, 1,
                                              1, 1, 1, 1,
                                              1, 1, 1, 1},
                                     3, 4);

    position min = getMinValuePos(c);
    position minTrue = {0, 0};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
}

void test_getMinValuePos_NegativeNumbers() {
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

void test_getMaxValuePos_identicalElements() {
    matrix c = createMatrixFromArray((int[]) {1, 1, 1},
                                     1, 1);

    position max = getMaxValuePos(c);
    position maxTrue = {0, 0};

    assert(max.colIndex == maxTrue.colIndex && max.rowIndex == maxTrue.rowIndex);
}

void test_getMaxValuePos_NegativeNumbers() {
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

void test_mulMatrices_Square() {
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

void test_mulMatrices_NonSquare() {
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

void test_mulMatrices_toEMatrix() {
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

/******** test ques *********/

void test_swapRowsMaxMinElement_inOneRow() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    0, 99, 1,
                    2, 3, 4,
                    5, 6, 7
            },
            3, 3);

    swapRowsMaxMinElement(c1);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    0, 99, 1,
                    2, 3, 4,
                    5, 6, 7
            },
            3, 3);

    assert(areTwoMatricesEqual(c1, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(cTrue);
}

void test_swapRowsMaxMinElement_classic() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    0, 8, 1,
                    2, 3, 4,
                    5, 6, 9},
            3, 3);

    swapRowsMaxMinElement(c1);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    5, 6, 9,
                    2, 3, 4,
                    0, 8, 1
            },
            3, 3);

    assert(areTwoMatricesEqual(c1, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(cTrue);
}

void test_swapRowsMaxMinElement() {
    test_swapRowsMaxMinElement_inOneRow();
    test_swapRowsMaxMinElement_classic();
}

void test_sortRowsByMaxElement_classic() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3);

    sortRowsByMaxElement(c1);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3);

    assert(areTwoMatricesEqual(c1, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(cTrue);
}

void test_sortRowsByMaxElement_oneRow() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    5, 0, 2, 4
            },
            1, 4);

    sortRowsByMaxElement(c1);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    5, 0, 2, 4
            },
            1, 4);

    assert(areTwoMatricesEqual(c1, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(cTrue);
}

void test_sortRowsByMaxElement_oneCol() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    5, 0, 2, 4
            },
            4, 1);

    sortRowsByMaxElement(c1);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    0, 2, 4, 5
            },
            4, 1);

    assert(areTwoMatricesEqual(c1, cTrue));

    freeMemMatrix(c1);
    freeMemMatrix(cTrue);
}

void test_sortRowsByMaxElement_qualMax() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 11, 3,
                    11, 5, 11, 8, 2, 11,
                    6, 11, 4, 11, 8, 3
            },
            3, 6);

    sortRowsByMaxElement(c);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 11, 3,
                    11, 5, 11, 8, 2, 11,
                    6, 11, 4, 11, 8, 3
            },
            3, 6);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_sortRowsByMaxElement() {
    test_sortRowsByMaxElement_classic();
    test_sortRowsByMaxElement_oneRow();
    test_sortRowsByMaxElement_oneCol();
    test_sortRowsByMaxElement_qualMax();
}

void test_sortColsByMinElement_classic() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6);

    sortColsByMinElement(c);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            },
            3, 6);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_sortColsByMinElement_oneRow() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    5, 0, 2, 4
            },
            1, 4);

    sortColsByMinElement(c);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    0, 2, 4, 5
            },
            1, 4);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_sortColsByMinElement_oneCol() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    5, 0, 2, 4
            },
            1, 4);

    sortColsByMinElement(c);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    0, 2, 4, 5
            },
            1, 4);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_sortColsByMinElement_qualMin() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, -1, 3,
                    -1, 5, -1, 8, 2, -1,
                    6, -1, 4, -1, 8, 3
            },
            3, 6);

    sortColsByMinElement(c);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, -1, 3,
                    -1, 5, -1, 8, 2, -1,
                    6, -1, 4, -1, 8, 3
            },
            3, 6);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_classic();
    test_sortColsByMinElement_oneRow();
    test_sortColsByMinElement_oneCol();
    test_sortColsByMinElement_qualMin();
}

void test_getSquareOfMatrixIfSymmetric_SymmetricMatrix() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    2, 1, 3
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&c);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    54, 17, 21,
                    17, 66, 13,
                    21, 13, 14
            },
            3, 3);

    assert(areTwoMatricesEqual(c, m2));

    freeMemMatrix(c);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_oneElem() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);

    getSquareOfMatrixIfSymmetric(&c);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);

    assert(areTwoMatricesEqual(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_SymmetricMatrix();
    test_getSquareOfMatrixIfSymmetric_oneElem();
}

void test_isMutuallyInverseMatrices_MatrixProduceIsEMatrixOrder2() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            },
            2, 2);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    7, -4,
                    -5, 3
            },
            2, 2);

    assert(isMutuallyInverseMatrices(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_isMutuallyInverseMatrices_MatrixProduceIsEMatrixOrder3() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    assert(isMutuallyInverseMatrices(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_isMutuallyInverseMatrices_MatrixProduceIsEMatrixOrder4() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    2, 1, 0, 0,
                    3, 2, 0, 0,
                    1, 1, 3, 4,
                    2, -1, 2, 3
            },
            4, 4);

    matrix cTrue = createMatrixFromArray(
            (int[]) {
                    2, -1, 0, 0,
                    -3, 2, 0, 0,
                    31, -19, 3, -4,
                    -23, 14, -2, 3
            },
            4, 4);

    assert(isMutuallyInverseMatrices(c, cTrue));

    freeMemMatrix(c);
    freeMemMatrix(cTrue);
}

void test_isMutuallyInverseMatrices_MatrixProduceIsNotEMatrixOrder2() {
    matrix c = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    5, 7
            },
            2, 2);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    7, 4,
                    -5, 3
            },
            2, 2);

    assert(!isMutuallyInverseMatrices(c, c2));

    freeMemMatrix(c);
    freeMemMatrix(c2);
}

void test_isMutuallyInverseMatrices_MatrixProduceIsNotEMatrixOrder3() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    1, -1, -1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    assert(!isMutuallyInverseMatrices(c1, c2));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
}

void test_isMutuallyInverseMatrices_MatrixProduceIsNotEMatrixOrder4() {
    matrix c1 = createMatrixFromArray(
            (int[]) {
                    2, 1, 0, 1,
                    3, 2, 0, 0,
                    1, 1, 3, 4,
                    2, -1, 2, 3
            },
            4, 4);

    matrix c2 = createMatrixFromArray(
            (int[]) {
                    1, -1, 0, 0,
                    -3, 2, 0, 0,
                    31, -19, 3, -4,
                    -23, 14, -2, 3
            },
            4, 4);

    assert(!isMutuallyInverseMatrices(c1, c2));

    freeMemMatrix(c1);
    freeMemMatrix(c2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_MatrixProduceIsEMatrixOrder2();
    test_isMutuallyInverseMatrices_MatrixProduceIsEMatrixOrder3();
    test_isMutuallyInverseMatrices_MatrixProduceIsEMatrixOrder4();
    test_isMutuallyInverseMatrices_MatrixProduceIsNotEMatrixOrder2();
    test_isMutuallyInverseMatrices_MatrixProduceIsNotEMatrixOrder3();
    test_isMutuallyInverseMatrices_MatrixProduceIsNotEMatrixOrder4();
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -2, -5, -4,
                    -1, -3, -6, -3,
                    -3, -2, -1, -2
            },
            3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -3 + -1 + -2 + -3 + -4);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
                    4, 5, 3,
                    1, 5, 7,
                    6, 4, 3
            },
            6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 6 + 4 + 5 + 7 + 3 + 1 + 3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
                    -4, -5, -3,
                    -1, -5, -7,
                    -6, -4, -3
            },
            6, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -6 + -1 + -3 + -5 + -1 + -1 + -3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 1, 3,
                    1, 8, 1,
                    7, 1, 2,
            },
            3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 7 + 1 + 1 + 3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, -1, -3,
                    -1, -8, -1,
                    -7, -1, -2,
            },
            3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == -7 + -1 + -1 + -3);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneCol() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3,
                    1,
                    -7,
                    4,
                    -1,
                    6
            },
            6, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal_oneRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3, 1, -7, 4, -1, 6
            },
            1, 6);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 1 + -7 + 4 + -1 + 6);

    freeMemMatrix(m1);
}


void test_findSumOfMaxesOfPseudoDiagonal_oneElem() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    -3
            },
            1, 1);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 0);

    freeMemMatrix(m1);
}


void test_findSumOfMaxesOfPseudoDiagonal() {
    test_findSumOfMaxesOfPseudoDiagonal_positiveHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeHorizontalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_negativeVerticalRectangleMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_oneRow();
    test_findSumOfMaxesOfPseudoDiagonal_oneCol();
    test_findSumOfMaxesOfPseudoDiagonal_oneElem();
    test_findSumOfMaxesOfPseudoDiagonal_negativeSquareMatrix();
    test_findSumOfMaxesOfPseudoDiagonal_positiveSquareMatrix();

}

void test_getMinInArea_topLeftCorner() {
    matrix c = createMatrixFromArray((int[]) {99, 1, 2, 3,
                                              4, 5, 6, 7,
                                              8, 9, 10, 11,
                                              12, 13, 14, 15}, 4, 4);

    int minElem = getMinInArea(c);

    assert(minElem == 99);

    freeMemMatrix(c);
}

void test_getMinInArea_upperRightCorner() {
    matrix c = createMatrixFromArray((int[]) {0, 1, 2, 99,
                                              4, 5, 6, 7,
                                              8, 9, 10, 11,
                                              12, 13, 14, 15}, 4, 4);

    int minElem = getMinInArea(c);

    assert(minElem == 99);

    freeMemMatrix(c);
}

void test_getMinInArea_centerBottom4x4() {
    matrix c = createMatrixFromArray((int[]) {0, 1, -2, 99,
                                              4, 5, 6, 7,
                                              8, 9, 10, 11,
                                              12, 199, 14, 15}, 4, 4);

    int minElem = getMinInArea(c);

    assert(minElem == -2);

    freeMemMatrix(c);
}

void test_getMinInArea_verticalMatrixCenterBottomRow() {
    matrix c = createMatrixFromArray((int[]) {0, 1, -2,
                                              4, 5, 6,
                                              8, 9, 10,
                                              12, 199, 14}, 4, 3);

    int minElem = getMinInArea(c);

    assert(minElem == -2);

    freeMemMatrix(c);
}

void test_getMinInArea_bottoLeftCorner() {
    matrix c = createMatrixFromArray((int[]) {0, 1, -2, 99,
                                              4, 5, 6, 7,
                                              8, 9, 10, 11,
                                              120, 12, 14, 15}, 4, 4);

    int minElem = getMinInArea(c);

    assert(minElem == -2);

    freeMemMatrix(c);
}

void test_getMinInArea_lowerRightCorner() {
    matrix c = createMatrixFromArray((int[]) {56, 71, -7, 94,
                                              0, 1, -2, 99,
                                              4, 5, 6, 7,
                                              8, 9, 10, 11,
                                              120, 12, 14, 150}, 5, 4);

    int minElem = getMinInArea(c);

    assert(minElem == -7);

    freeMemMatrix(c);
}

void test_getMinInArea() {
    test_getMinInArea_topLeftCorner();
    test_getMinInArea_upperRightCorner();
    test_getMinInArea_centerBottom4x4();
    test_getMinInArea_verticalMatrixCenterBottomRow();
    test_getMinInArea_bottoLeftCorner();
    test_getMinInArea_lowerRightCorner();
}

void test_ques() {
    test_swapRowsMaxMinElement();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
}