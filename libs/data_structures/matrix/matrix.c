#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>
#include "../../algorithms/algorithm.h"
#include <stdlib.h>

// АНЕКДОТ-оскорбление два :
// как же я ща мощно ничего из себя не представляю

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int indexRows = 0; indexRows < nRows; indexRows++)
        values[indexRows] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int indexMatrix = 0; indexMatrix < nMatrices; indexMatrix++)
        ms[indexMatrix] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int indexRows = 0; indexRows < m.nRows; indexRows++)
        free(m.values[indexRows]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int indexMatrix = 0; indexMatrix < nMatrices; indexMatrix++)
        freeMemMatrix((matrix) ms[indexMatrix]);
    free(ms->values);
}

void inputMatrix(matrix m) {
    for (int indexRows = 0; indexRows < m.nRows; indexRows++)
        for (int indexCols = 0; indexCols < m.nCols; indexCols++)
            scanf("%d", &m.values[indexRows][indexCols]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int indexMatrix = 0; indexMatrix < nMatrices; indexMatrix++)
        inputMatrix(ms[indexMatrix]);
}

void outputMatrix(matrix m) {
    for (int indexRows = 0; indexRows < m.nRows; indexRows++) {
        for (int indexCols = 0; indexCols < m.nCols; indexCols++)
            printf("%d ", m.values[indexRows][indexCols]);
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int indexMatrix = 0; indexMatrix < nMatrices; indexMatrix++) {
        outputMatrix(ms[indexMatrix]);
        printf("/n");
    }
}

void isIndexMatrixCorrect(int size, int index) {
    if (index >= size) {
        fprintf(stderr, "Index {%d} out of the range", index);
        exit(1);
    }
}

void swapRowsWithVerificationIndex(matrix m, int i1, int i2) {
    isIndexMatrixCorrect(m.nRows, i1);
    isIndexMatrixCorrect(m.nRows, i2);

    swap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapRowsWithoutVerificationIndex(matrix m, int i1, int i2) {
    swap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumnsWithVerificationIndex(matrix m, int j1, int j2) {
    isIndexMatrixCorrect(m.nCols, j1);
    isIndexMatrixCorrect(m.nCols, j2);

    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        swap(&m.values[indexRow][j1], &m.values[indexRow][j2],
             sizeof(int));
}

void swapColumnsWithoutVerificationIndex(matrix m, int j1, int j2) {
    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        swap(&m.values[indexRow][j1], &m.values[indexRow][j2],
             sizeof(int));
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int indexArray = 0;
    for (int indexRow = 0; indexRow < nRows; indexRow++)
        for (int indexCol = 0; indexCol < nCols; indexCol++)
            m.values[indexRow][indexCol] = a[indexArray++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int indexArray = 0;
    for (int indexMatrix = 0; indexMatrix < nMatrices; indexMatrix++)
        for (int indexRow = 0; indexRow < nRows; indexRow++)
            for (int indexCol = 0; indexCol < nCols; indexCol++)
                ms[indexMatrix].values[indexRow][indexCol] =
                        values[indexArray++];

    return ms;
}
