#ifndef COURSE_VECTORVOID_H
#define COURSE_VECTORVOID_H

#include <limits.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений
// и размером базового типа baseTypeSize
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти на newCapacity, выделенное
// под хранение элементов вектора v
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную
// под неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// удаляет элементы вектора v
void clearV(vectorVoid *v);

// освобождает память выделенную вектору v
void deleteVectorV(vectorVoid *v);

// возвращает "истина" если вектор v
// является пустым, иначе "ложь"
bool isEmptyV(vectorVoid *v);

// возвращает "истина" если вектор v
// является полным, иначе "ложь"
bool isFullV(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v, size_t index, void *destination);

// записывает на index-ый элемент вектора v значение,
// расположенное по адресу source
void setVectorValueV(vectorVoid *v, size_t index, void *source);

// удаляет последний элемент из вектора v
void popBackV(vectorVoid *v);

// добавляет элемент x в конец вектора
// v. Если вектор заполнен, увеличивает
// количество выделенной ему памяти в 2 раза
void pushBackV(vectorVoid *v, void *source);

#endif
