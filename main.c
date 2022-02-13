#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <float.h>
#include "libs/algorithms/algorithm.h"
#include "libs/test/testMatrix/testMatrix.h"
#include "libs/data_structures/matrix/matrix.h"


int main() {
    // я перенесу это в тесты позже, не переживайте
    matrix c = createMatrixFromArray((int[]){1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12},
                                     3, 4);

    position min = getMinValuePos(c);
    position max = getMaxValuePos(c);
    position minTrue = {0, 0};
    position maxTrue = {2, 3};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
    assert(max.colIndex == maxTrue.colIndex && max.rowIndex == maxTrue.rowIndex);

    return 0;
}
