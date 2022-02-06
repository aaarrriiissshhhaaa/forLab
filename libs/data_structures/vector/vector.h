#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений
vector createVector(size_t n);

// изменяет количество памяти на newCapacity, выделенное
// под хранение элементов вектора v
void reserve(vector *v, size_t newCapacity);

// удаляет элементы вектора v
void clear(vector *v);

// освобождает память, выделенную
// под неиспользуемые элементы вектора v
void shrinkToFit(vector *v);

// освобождает память выделенную вектору v
void deleteVector(vector *v);

// возврощает "истина" если вектор v
// является пустым, иначе "ложь"
bool isEmpty(vector *v);

// возврощает "истина" если вектор v
// является полным, иначе "ложь"
bool isFull(vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i);

// добавляет элемент x в конец вектора
// v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза
void pushBack(vector *v, int x);

// удаляет последний элемент из вектора v
void popBack(vector *v);


// возвращает указатель на index-ый элемент вектора v
int *atVector(vector *v, size_t index);

// возвращает указатель на последний элемент вектора v
int *back(vector *v);

// возвращает указатель на нулевой элемент вектора v
int *front(vector *v);

#endif