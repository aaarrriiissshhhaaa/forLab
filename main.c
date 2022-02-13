#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"

int main() {
    matrix c = createMatrixFromArray((int []) {1, 1, 1,
                                              2, 2, 2,
                                              3, 3, 3},
                                     3, 3);
    swapRowsWithVerificationIndex(c, 1, 2);
    outputMatrix(c);
    printf("\n");

    swapRowsWithoutVerificationIndex(c, 1, 2);
    outputMatrix(c);
    printf("\n");

    matrix b = createMatrixFromArray((int []) {1, 2, 3,
                                               1, 2, 3,
                                               1, 2, 3},
                                     3, 3);

    swapColumnsWithVerificationIndex(b, 1, 2);
    outputMatrix(b);
    printf("\n");

    swapColumnsWithoutVerificationIndex(b, 1, 2);
    outputMatrix(b);
    printf("\n");

    return 0;
}
