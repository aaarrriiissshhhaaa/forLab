#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"


int criteria(int * m, int a){
    return m[0];
}
int main() {
    matrix c = createMatrixFromArray((int []) {9, 1, 1,
                                              3, 2, 2,
                                              1, 3, 3},
                                     3, 3);
    insertionSortRowsMatrixByRowCriteria(c, criteria);
    outputMatrix(c);
    printf("\n");

    matrix b = createMatrixFromArray((int []) {9, 7, 3,
                                               1, 2, 3,
                                               1, 2, 3},
                                     3, 3);

    insertionSortColsMatrixByColCriteria(b, criteria);
    outputMatrix(b);
    printf("\n");

    return 0;
}
