#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"


#define N 4
void swapRowsMaxMinElement(matrix m){
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);

    swapRowsWithoutVerificationIndex(m, min.rowIndex, max.rowIndex);
}

int getMax(int *a, int size){
    int max = a[0];
    for (int i = 1; i < size; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}


void sortRowsByMinElement(matrix m){
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int main() {
    //тестов пока нет. Напишу может быть завтра.
    int a[] = {1, 2, 3, 4};

    //printf("%d ", getMax(a, 4));

    matrix c = createMatrixFromArray((int[]){7, 1, 2,
                                             1, 8, 1,
                                             3, 2, 3}, 3, 3);

    sortRowsByMinElement(c);
    outputMatrix(c);

    freeMemMatrix(c);
    return 0;
}
