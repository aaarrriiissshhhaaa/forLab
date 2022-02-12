#include "matrix.h"
#include "malloc.h"

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

void freeMemMatrix(matrix m){
    for (int indexRows = 0; indexRows < m.nRows; indexRows++)
        free(m.values[indexRows]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for (int indexMatrix = 0; indexMatrix < nMatrices; ++indexMatrix)
        freeMemMatrix((matrix)ms[indexMatrix]);
    free(ms->values);
}

