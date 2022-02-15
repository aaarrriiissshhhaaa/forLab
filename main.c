#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"

// упорядочивает массив а разммера size по неубыванию
void selectionSort(long long *a, const int size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1 ; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos], sizeof(long long));
    }
}

bool isUnique(long long *a, int size){
    selectionSort(a, size);
    bool isUnique = true;

    for (int i = 0; i < size - 1 && isUnique; i++)
        isUnique = a[i] != a[i + 1];

    return isUnique;
}

long long getSum(int *a, int size){
    long long sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasEqualSumOfRows(matrix m, int nRows, int nCols){
        long long rowsSums[m.nRows];
        for (int i = 0; i < m.nRows; i++)
            rowsSums[i] = getSum(m.values[i], m.nCols);

        if (isUnique(rowsSums, m.nRows))
            transposeSquareMatrix(m);
}

int main() {
    matrix c = createMatrixFromArray((int[]) {35, 1, 3,
                                              4, 5, 6,
                                              7, 8, 9,
                                              10, 56, 12}, 4, 3);

    printf("%d\n", getMinInArea(c));
    outputMatrix(c);

    freeMemMatrix(c);
    return 0;
}
