#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <stdlib.h>

// отдельно напомню rows - строки
// cols - стобцы, УЧИМ АНГЛИЙСКИЙ ВМЕСТЕ
typedef struct matrix {
    int **values;   // элементы матрицы
    int nRows;      // количество рядов
    int nCols;      // количество столбцов
} matrix;

// отдельно напомню rows - строки
// cols - стобцы, УЧИМ АНГЛИЙСКИЙ ВМЕСТЕ
typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// возвращает матрицу размером nRows на nCols,
// размещённую в динамической памяти
matrix getMemMatrix(int nRows, int nCols);

// возвращает массив из nMatrices матриц
// размером nRows на nCols, размещённый
// в динамической памяти
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под
// хранение матрицы m
void freeMemMatrix(matrix m);

// освобождает память, выделенную под хранение
// массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

// ввод матрицы m
void inputMatrix(matrix m);

// ввод массива из nMatrices матриц,
// хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// вывод матрицы m
void outputMatrix(matrix m);

// вывод массива из nMatrices матриц,
// хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

// обмен строк матрицы m
// с порядковыми номерами i1 и i2
// с проверкой индексов строк
void swapRowsWithVerificationIndex(matrix m, int i1, int i2);

// обмен строк матрицы m
// с порядковыми номерами i1 и i2
// без проверки индексов строк
void swapRowsWithoutVerificationIndex(matrix m, int i1, int i2);

// обмен столбцов матрицы m
// с порядковыми номерами i1 и i2
// с проверкой индексов столбцов
void swapColumnsWithVerificationIndex(matrix m, int j1, int j2);

// обмен столбцов матрицы m
// с порядковыми номерами i1 и i2
// без проверки индексов столбцов
void swapColumnsWithoutVerificationIndex(matrix m, int j1, int j2);

// возвращает матрицу, размера nRows на nCols,
// построенного из элементов массива a,
// размещенную в динамической памяти
matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows, int nCols);

#endif