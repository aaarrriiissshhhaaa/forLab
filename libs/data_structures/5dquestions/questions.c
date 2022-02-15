#include "questions.h"
#include "../../algorithms/algorithm.h"
#include "../../data_structures/matrix/matrix.h"

/********************** 1 ***************************/

void swapRowsMaxMinElement(matrix m) {
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);

    swapRowsWithoutVerificationIndex(m, min.rowIndex, max.rowIndex);
}

/********************** 2 ***************************/

int getMax(int *a, int size) {
    int max = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}


void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

/********************** 3 ***************************/

int getMin(int *a, int size) {
    int min = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

/********************** 4 ***************************/

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

/********************** 6 ***************************/
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

/********************** 7 ***************************/
int max(int a, int b) {
    return a > b ? a : b;
}

int getMaxElementDiag(matrix m, int indexRow, int indexCol) {
    int maxElement = m.values[indexRow++][indexCol++];

    while (indexRow < m.nRows && indexCol < m.nCols) {
        maxElement = max(maxElement, m.values[indexRow++][indexCol++]);
    }

    return maxElement;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sumMaxDiag = 0;

    // сумма ниже главной диагонали
    for (int indexRow = 1; indexRow < m.nRows; indexRow++)
        sumMaxDiag += getMaxElementDiag(m, indexRow, 0);

    // сумма выше главной диагонали
    for (int indexCol = 1; indexCol < m.nCols; indexCol++)
        sumMaxDiag += getMaxElementDiag(m, 0, indexCol);

    return sumMaxDiag;
}


/********************** 8 ***************************/

int min(int a, int b) {
    return a < b ? a : b;
}

int getMinArray(int *a, int size) {
    int minValue = a[0];

    for (int i = 1; i < size; i++)
        if (a[i] < minValue)
            minValue = a[i];
    return minValue;
}


int getMinInArea(matrix m) {
    position maxElement = getMaxValuePos(m);

    position elemLeft = maxElement;
    position elemRight = maxElement;

    int minElem = m.values[maxElement.rowIndex][maxElement.colIndex];

    while (elemRight.colIndex < m.nCols && elemLeft.colIndex >= 0) {
        minElem = min(getMin(m.values[elemLeft.rowIndex] + elemLeft.colIndex,
                             elemRight.colIndex - elemLeft.colIndex + 1),
                      minElem);
        elemLeft.colIndex--;
        elemLeft.rowIndex--;
        elemRight.colIndex++;
        elemRight.rowIndex--;

    }

    if (elemRight.colIndex >= m.nCols) {
        elemRight.colIndex--;
        while (elemLeft.rowIndex >= 0 && elemLeft.colIndex >= 0) {
            minElem = min(getMin(m.values[elemLeft.rowIndex] + elemLeft.colIndex,
                                 elemRight.colIndex - elemLeft.colIndex + 1),
                          minElem);
            elemLeft.colIndex--;
            elemLeft.rowIndex--;
            elemRight.rowIndex--;
        }
    }

    if (elemLeft.colIndex < 0) {
        elemLeft.colIndex++;
        while (elemLeft.rowIndex >= 0 && elemRight.colIndex < m.nCols) {
            minElem = min(getMin(m.values[elemLeft.rowIndex] + elemLeft.colIndex,
                                 elemRight.colIndex - elemLeft.colIndex + 1),
                          minElem);
            elemLeft.rowIndex--;
            elemRight.rowIndex--;
            elemRight.colIndex++;
        }
    }

    while (elemLeft.rowIndex >= 0) {
        minElem = min(getMin(m.values[elemLeft.rowIndex], m.nCols),
                      minElem);
        elemLeft.rowIndex--;
        elemRight.rowIndex--;
    }

    return minElem;
}

/********************** 5 ***************************/

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