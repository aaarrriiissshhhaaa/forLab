#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include <memory.h>
#include <math.h>

double getScalarProduct(const int *a, const int *b, int countV) {
    double scalarProduct = 0;
    for (int i = 0; i < countV; i++)
        scalarProduct += a[i] * b[i];

    return scalarProduct;
}

double getVectorLength(const int *a, int n) {
    double length = 0;
    for (int i = 0; i < n; i++)
        length += a[i] * a[i];

    return sqrt(length);
}

double getCosine(int *a, int *b, int n) {
    double lengthA = getVectorLength(a, n);
    double lengthB = getVectorLength(b, n);

    if (lengthA == 0 || lengthB == 0) {
        fprintf(stderr, "vector Null");
        exit(1);
    }

    return getScalarProduct(a, b, n) / (lengthA * lengthB);
}

int getVectorIndexWithMaxAngle(matrix m, int *vector) {
    double cornerMax = getCosine(m.values[0], vector, m.nCols);
    int cornerMaxPos = 0;
    for (int i = 0; i < m.nRows; i++) {
        double cornNuw = getCosine(m.values[i], vector, m.nCols);
        if (cornNuw < cornerMax) {
            cornerMax = cornNuw;
            cornerMaxPos = i;
        }
    }

    return cornerMaxPos;
}

void test_getVectorIndexWithMaxAngle_oneRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 7, 11
            },
            1, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 0);

    freeMemMatrix(m);
}


void test_getVectorIndexWithMaxAngle_negativeCos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 7, -11,
                    4, -13, -10,
                    7, -1, -1,
                    12, 1, -56
            },
            4, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 1);

    freeMemMatrix(m);
}

void test_getVectorIndexWithMaxAngle_classicMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    -1, 7, -11,
                    4, 13, 10,
                    7, 1, 1,
                    12, 1, -6
            },
            4, 3);

    int v[] = {1, 2, 3};

    assert(getVectorIndexWithMaxAngle(m, v) == 0);

    freeMemMatrix(m);
}

void test_getVectorIndexWithMaxAngle() {
    test_getVectorIndexWithMaxAngle_negativeCos();
    test_getVectorIndexWithMaxAngle_classicMatrix();
    test_getVectorIndexWithMaxAngle_oneRow();
}

int main() {
    test_getVectorIndexWithMaxAngle();

    return 0;
}