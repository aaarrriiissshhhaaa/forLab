#include "vector.h"

vector createVector(size_t n) {
    int *data;
    if (n != 0) {
        data = (int *) malloc(sizeof(int) * n);
        if (data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    } else
        data = NULL;

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        return;
    }
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    if (v->size > newCapacity) {
        v->size = newCapacity;
    }
    v->capacity = newCapacity;
}

void clear(vector *v){
    v->size = 0;
};

void shrinkToFit(vector *v){
    reserve(v, v->size);
};

void deleteVector(vector *v){
    free(v->data);
    v->size = 0;
    v->capacity = 0;
};
