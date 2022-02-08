#include "vectorVoid.h"
#include <malloc.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//возвращает структуру-дескриптор вектор из n значений
//и размером базового типа baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void * data;
    if (n != 0) {
        data = malloc(baseTypeSize * n);
        if (data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else
        data = NULL;

    return (vectorVoid) {data, 0, n, baseTypeSize};
};

// изменяет количество памяти на newCapacity, выделенное
// под хранение элементов вектора v
void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = realloc(v->data, v->baseTypeSize * newCapacity);
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->capacity = newCapacity;
        if (newCapacity < v->size)
            v->size = newCapacity;
    } else
        deleteVectorV(v);
}


// освобождает память, выделенную
// под неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
};

// удаляет элементы вектора v
void clearV(vectorVoid *v){
    v->size = 0;
};

// освобождает память выделенную вектору v
void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->data = NULL;
    clearV(v);
    v->capacity = 0;
};
