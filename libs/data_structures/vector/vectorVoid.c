#include "vectorVoid.h"
#include <malloc.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

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
}

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
}

// удаляет элементы вектора v
void clearV(vectorVoid *v){
    v->size = 0;
}

// освобождает память выделенную вектору v
void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->data = NULL;
    clearV(v);
    v->capacity = 0;
}

//возвращает "истина" если вектор v
//является пустым, иначе "ложь"
bool isEmptyV(vectorVoid *v){
    return !v->size;
};

//возвращает "истина" если вектор v
//является полным, иначе "ложь"
bool isFullV(vectorVoid *v){
    return v->size == v->capacity;
};

//записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }

    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
};

//записывает на index-ый элемент вектора v значение,
//расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source){
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
};

// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v){
    if (isEmptyV(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }

    v->size--;
};

// добавляет элемент x в конец вектора
// v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза
void pushBackV(vectorVoid *v, void *source){
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);

    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
};
