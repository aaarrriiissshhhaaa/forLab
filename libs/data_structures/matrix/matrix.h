#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

#include <stdlib.h>
#include <stdbool.h>
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
// с порядковыми номерами rowIndex1 и rowIndex2
// с проверкой индексов строк
void swapRowsWithVerificationIndex(matrix m, int rowIndex1, int rowIndex2);

// обмен строк матрицы m
// с порядковыми номерами rowIndex1 и rowIndex2
// без проверки индексов строк
void swapRowsWithoutVerificationIndex(matrix m, int rowIndex1, int rowIndex2);

// обмен столбцов матрицы m
// с порядковыми номерами colIndex1 и colIndex2
// с проверкой индексов столбцов
void swapColumnsWithVerificationIndex(matrix m, int colIndex1, int colIndex2);

// обмен столбцов матрицы m
// с порядковыми номерами colIndex1 и colIndex2
// без проверки индексов столбцов
void swapColumnsWithoutVerificationIndex(matrix m, int colIndex1, int colIndex2);

// возвращает матрицу, размера nRows на nCols,
// построенного из элементов массива a,
// размещенную в динамической памяти
matrix createMatrixFromArray(const int *a, int nRows, int nCols);

// возвращает указатель на нулевую матрицу массива
// из nMatrices матриц, размещенных в динамической памяти,
// построенных из элементов массива values
matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices,
                                     int nRows, int nCols);

// выполняет сортировку вставками строк
// матрицы m по неубыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int));

// выполняет сортировку вставками
// столбцов матрицы m по неубыванию значения функции
// criteria применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int));

// возвращает значение ’истина’, если
// матрица m является квадратной, 'ложь' – в противном случае.
bool isSquareMatrix(matrix m);

// возвращает значение
// ’истина’, если матрицы m1 и m2 равны,
// 'ложь' – в противном случае
bool twoMatricesEqual(matrix m1, matrix m2);

// возвращает значение ’истина’, если матрица
// m является единичной,
// 'ложь' – в противном случае.
bool isEMatrix(matrix m);

// возвращает значение ’истина’, если
// матрица m является симметричной,
// 'ложь' – в противном случае
bool isSymmetricMatrix(matrix m);

//void transposeSquareMatrix(matrix m) {

//}

#endif