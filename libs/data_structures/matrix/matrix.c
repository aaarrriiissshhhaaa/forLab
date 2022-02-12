#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

// Я СОЗДАЛА СТРУКТУРУ. ПЕРВЫЙ АНЕКДОТ-оскорбление ПОШЁЛ :
// когда тебе в следующий раз станет грустно,
// вспомни
// что у тебя ещё и ОП

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


