#include "matrix.h"
#include <malloc.h>
#include <stdio.h>
#include <stdint.h>
#include "../../algorithms/algorithm.h"
#include <stdlib.h>
#include <string.h>

// АНЕКДОТ-оскорбление эйт :
// как человек ты на 50% обесценился

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

void swapRowsWithVerificationIndex(matrix m, int rowIndex1, int rowIndex2) {
    isIndexMatrixCorrect(m.nRows, rowIndex1);
    isIndexMatrixCorrect(m.nRows, rowIndex2);

    swap(&m.values[rowIndex1], &m.values[rowIndex2], sizeof(int *));
}

void swapRowsWithoutVerificationIndex(matrix m, int rowIndex1, int rowIndex2) {
    swap(&m.values[rowIndex1], &m.values[rowIndex2], sizeof(int *));
}

void swapColumnsWithVerificationIndex(matrix m, int colIndex1, int colIndex2) {
    isIndexMatrixCorrect(m.nCols, colIndex1);
    isIndexMatrixCorrect(m.nCols, colIndex2);

    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        swap(&m.values[indexRow][colIndex1], &m.values[indexRow][colIndex2],
             sizeof(int));
}

void swapColumnsWithoutVerificationIndex(matrix m, int colIndex1, int colIndex2) {
    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        swap(&m.values[indexRow][colIndex1], &m.values[indexRow][colIndex2],
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

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int rowsCriteria[m.nRows];
    for (int indexCriteria = 0; indexCriteria < m.nRows; indexCriteria++)
        rowsCriteria[indexCriteria] = criteria(m.values[indexCriteria],
                                               m.nCols);

    for (int indexRow = 1; indexRow < m.nRows; indexRow++)
        for (int indexCriteria = indexRow; indexCriteria > 0 &&
                                           rowsCriteria[indexCriteria - 1]
                                           > rowsCriteria[indexCriteria];
                                            indexCriteria--) {
            swap(&rowsCriteria[indexCriteria - 1],
                 &rowsCriteria[indexCriteria], sizeof(int));
            swapRowsWithoutVerificationIndex(m, indexCriteria,
                                             indexCriteria - 1);
        }
}

// надо привести в норму индексы чот ты подзапуталась моя зайка
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int colsCriteria[m.nCols];
    for (int indexRow = 0; indexRow < m.nCols; indexRow++) {
        int colsMatrix[m.nRows];
        for (int indexCol = 0; indexCol < m.nRows; indexCol++)
            colsMatrix[indexCol] = m.values[indexCol][indexRow];

        colsCriteria[indexRow] = criteria(colsMatrix, m.nRows);
    }
    for (int indexRow = 1; indexRow < m.nCols; indexRow++)
        for (int indexCriteria = indexRow; indexCriteria > 0 &&
                                           colsCriteria[indexCriteria - 1]
                                           > colsCriteria[indexCriteria];
                                                indexCriteria--) {
            swap(&colsCriteria[indexCriteria - 1],
                 &colsCriteria[indexCriteria], sizeof(int));
            swapColumnsWithoutVerificationIndex(m, indexCriteria,
                                                indexCriteria - 1);
        }
}

bool isSquareMatrix(matrix m){
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2){
    bool isEqual = m1.nRows == m2.nRows && m1.nCols == m2.nCols ? true : false;

    for (size_t i = 0; i <  m1.nRows && isEqual; i++) {
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols) != 0)
            isEqual = false;
    }

    return isEqual;
}

bool isEMatrix(matrix m){
    bool isEMatrix = isSquareMatrix(m) ? true : false;

    for (int indexRow = 0; indexRow < m.nRows && isEMatrix; indexRow++)
        for (int indexCol = 0; indexCol < m.nCols && isEMatrix; indexCol++)
            if (indexRow != indexCol && m.values[indexRow][indexCol] != 0
            || indexRow == indexCol && m.values[indexRow][indexRow] != 1)
                isEMatrix = false;

    return isEMatrix;
}
bool isSymmetricMatrix(matrix m){
    bool isSymmetric = isSquareMatrix(m) ? true : false;

    for (int indexRow = 0; indexRow < m.nRows && isSymmetric; indexRow++)
        for (int indexCol = 0; indexCol < indexRow && isSymmetric; indexCol++)
            if (m.values[indexRow][indexCol] != m.values[indexCol][indexRow])
                isSymmetric = false;

    return isSymmetric;
}

void transposeSquareMatrix(matrix m){
    if(isSquareMatrix(m) == 0){
        fprintf(stderr, "not square matrix :( ");
        exit(1);
    }

    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        for (int indexCol = 0; indexCol < indexRow; indexCol++)
            swap(&m.values[indexRow][indexCol],&m.values[indexCol][indexRow],
                 sizeof(int));
}

position getMinValuePos(matrix m){
    int minValues = m.values[0][0];
    position minPos = {0, 0};

    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        for (int indexCol = 0; indexCol < m.nCols; indexCol++)
            if (m.values[indexRow][indexCol] < minValues) {
                minValues = m.values[indexRow][indexCol];
                minPos.colIndex = indexCol;
                minPos.rowIndex = indexRow;
            }

    return minPos;
}

position getMaxValuePos(matrix m){
    int maxValues = m.values[0][0];
    position maxPos = {0, 0};

    for (int indexRow = 0; indexRow < m.nRows; indexRow++)
        for (int indexCol = 0; indexCol < m.nCols; indexCol++)
            if (m.values[indexRow][indexCol] > maxValues) {
                maxValues = m.values[indexRow][indexCol];
                maxPos.colIndex = indexCol;
                maxPos.rowIndex = indexRow;
            }

    return maxPos;
}

