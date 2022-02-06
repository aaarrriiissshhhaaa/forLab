#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

//изменяет количество памяти на newCapacity, выделенное
//под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

//удаляет элементы вектора v
void clear(vector *v);

//освобождает память, выделенную
//под неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

//освобождает память выделенную вектору v
void deleteVector(vector *v);


#endif