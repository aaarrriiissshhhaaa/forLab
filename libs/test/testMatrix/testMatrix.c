#include "../../data_structures/matrix/matrix.h"

#include "testMatrix.h"
#include <assert.h>
void test_getMinValuePos_classicMatrix(){
    matrix c = createMatrixFromArray((int[]){1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12},
                                     3, 4);

    position min = getMinValuePos(c);
    position minTrue = {0, 0};

    assert(min.colIndex == minTrue.colIndex && min.rowIndex == minTrue.rowIndex);
}

void test_getMaxValuePos_classicMatrix(){
    matrix c = createMatrixFromArray((int[]){1, 2, 3, 4,
                                             5, 6, 7, 8,
                                             9, 10, 11, 12},
                                     3, 4);

    position max = getMaxValuePos(c);
    position maxTrue = {2, 3};

    assert(max.colIndex == maxTrue.colIndex && max.rowIndex == maxTrue.rowIndex);
}