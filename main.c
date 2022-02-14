#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"

void swapMaxMinIndex(matrix m){
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);

    swapRowsWithoutVerificationIndex(m, min.rowIndex, max.rowIndex);
}

int main() {
    //тестов пока нет. Напишу может быть завтра.
    matrix c = createMatrixFromArray((int[]){4, 6, 7,
                                             2, 9, 1,
                                             3, 24, 8,
                                             11, 5, 0}, 4, 3);

    swapMaxMinIndex(c);
    outputMatrix(c);

    return 0;
}
