#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"

void swapRowsMaxMinElement(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);

    swapRowsWithoutVerificationIndex(m, min.rowIndex, max.rowIndex);
}

int getMax(int *a, int size) {
    int max = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}


void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int getMin(int *a, int size) {
    int min = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "matrices cannot be multiplied");
        exit(1);
    }

    matrix multiplicationMatrix = getMemMatrix(m1.nRows, m2.nCols);

    for (int indexRowM1 = 0; indexRowM1 < m1.nRows; indexRowM1++)
        for (int indexColM2 = 0; indexColM2 < m2.nCols; indexColM2++) {
            multiplicationMatrix.values[indexRowM1][indexColM2] = 0;
            for (int indexRowM2 = 0; indexRowM2 < m2.nRows; indexRowM2++)
                multiplicationMatrix.values[indexRowM1][indexColM2] +=
                        m1.values[indexRowM1][indexRowM2]
                        * m2.values[indexRowM2][indexColM2];
        }

    return (matrix) multiplicationMatrix;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if(isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2){
    return isEMatrix(mulMatrices(m1, m2));
}


int max(int a, int b){
    return a > b ? a : b;
}

int getMaxElementDiag(matrix m, int indexRow, int indexCol){
    int maxElement = m.values[indexRow][indexCol];

    while (indexRow < m.nRows && indexCol < m.nCols){
        maxElement = max(maxElement, m.values[indexRow++][indexCol++]);
    }

    return maxElement;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m){
    long long sumMaxDiag = 0;

    // сумма ниже главной диагонали
    for (int indexRow = 1; indexRow < m.nRows; indexRow++)
        sumMaxDiag += getMaxElementDiag(m, indexRow, 0);

    // сумма выше главной диагонали
    for (int indexCol = 1; indexCol < m.nCols; indexCol++)
        sumMaxDiag += getMaxElementDiag(m, 0, indexCol);

    return sumMaxDiag;
}

int main() {
    //тестов пока нет. Напишу может быть завтра.

    matrix c = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3 , 4);

    printf("%lld\n", findSumOfMaxesOfPseudoDiagonal(c));
    outputMatrix(c);

    freeMemMatrix(c);
    return 0;
}
