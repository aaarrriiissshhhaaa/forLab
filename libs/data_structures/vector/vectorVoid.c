#include "vectorVoid.h"
#include <malloc.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>


vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data;
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


void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}


void clearV(vectorVoid *v) {
    v->size = 0;
}


void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    clearV(v);
    v->capacity = 0;
}


bool isEmptyV(vectorVoid *v) {
    return !v->size;
};


bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
};

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }

    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
};

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
};


void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }

    v->size--;
};


void pushBackV(vectorVoid *v, void *source) {
    if (v->capacity == 0)
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, v->capacity * 2);

    char *destination = (char *) v->data + v->size * v->baseTypeSize;
    (v->size) ++;
    memcpy(destination, source, v->baseTypeSize);
};
