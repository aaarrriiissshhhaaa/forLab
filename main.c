#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include <memory.h>
#include <math.h>
#include "libs/data_structures/5dquestions/questions.h"

int main() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    4, 0, 1,
                    7, 0, 0,
                    0, 0, 0
            },
            4, 3);


    assert(countZeroRows(m) == 2);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    0, 0, 0,
                    0, 0, 0,
            },
            3, 3);

    assert(countZeroRows(m1) == 3);

    matrix * array = createArrayOfMatrixFromArray((int []){
                                                          0, 0, 0,
                                                          0, 0, 0,
                                                          0, 0, 0,
                                                  }, 3, 1, 3);



    printMatrixWithMaxZeroRows(array, 3);

    freeMemMatrix(m);
    freeMemMatrix(m1);
    freeMemMatrices(array, 3);
    
    return 0;
}