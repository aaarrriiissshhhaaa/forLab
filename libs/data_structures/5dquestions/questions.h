#ifndef COURSE_QUESTIONS_H
#define COURSE_QUESTIONS_H
#include "../matrix/matrix.h"

void swapRowsMaxMinElement(matrix m);

void sortRowsByMinElement(matrix m);

void sortColsByMinElement(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

void transposeIfMatrixHasEqualSumOfRows(matrix m, int nRows, int nCols);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int getMinInArea(matrix m);

#endif //COURSE_QUESTIONS_H
