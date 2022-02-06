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

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

// возврощает "истина" если вектор v
// является пустым, иначе "ложь"
bool isEmpty(vector *v) {
    return !v->size;
}

// возврощает "истина" если вектор v
// является полным, иначе "ложь"
bool isFull(vector *v) {
    return v->size == v->capacity;
}

// возвращает i-ый элемент вектора v
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

// добавляет элемент x в конец вектора
// v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза
void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        reserve(v, 1);
    } else if (isFull(v))
        reserve(v, v->capacity * 2);

    v->data[v->size] = x;
    (v->size)++;
}

void vectorIsEmptyError(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
}

// удаляет последний элемент из вектора v
void popBack(vector *v) {
    vectorIsEmptyError(v);

    (v->size)--;
}

// возвращает указатель на index-ый элемент вектора v
int *atVector(vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

// возвращает указатель на последний элемент вектора.
int *back(vector *v) {
    vectorIsEmptyError(v);

    return v->data + (v->size - 1);
}

int *front(vector *v) {
    vectorIsEmptyError(v);

    return v->data;
};
