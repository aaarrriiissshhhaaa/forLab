//
// Created by Lovem on 19.12.2021.
//

#ifndef COURSE_UNORDERED_ARRAY_SET_H
#define COURSE_UNORDERED_ARRAY_SET_H

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#include "../../algorithms/array/array.h"

#define unordered_array_set_base_type  int

typedef struct unordered_array_set {
    unordered_array_set_base_type *data;     // элементы множества
    size_t size;                             // количество элементов в множестве
    size_t capacity;                         // максимальное количество элементов в множестве
} unordered_array_set;

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(unordered_array_set_base_type)
                                         * capacity), 0, capacity};
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - size
size_t unordered_array_set_in(unordered_array_set *set, unordered_array_set_base_type value) {
    return linearSearch_(set->data, set->size, value);
}

// добавляет элемент value в множество set
void unordered_array_set_insert(unordered_array_set *set,
                                unordered_array_set_base_type value) {
    unordered_array_set_isAbleAppend(set);
    if (unordered_array_set_in(set, value) == set->size)
        append_(set->data, &set->size, value);
}

// возвращает множество, состоящее из элементов массива a размера size,
// с максимальным количеством элементов capasity
unordered_array_set unordered_array_set_create_from_array(
        const int *a, size_t size, size_t capacity) {
    unordered_array_set setResult = unordered_array_set_create(capacity);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&setResult, a[i]);
    return setResult;
}

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(
        unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    if (set1.size != set2.size)
        return false;
    else
        for (size_t i = 0; i < set1.size; i++)
            if (linearSearch_(set2.data, set2.size, set1.data[i]) == set2.size)
                return false;
    return true;
}

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(
        unordered_array_set *set, unordered_array_set_base_type value) {
    size_t posDeleteElement = unordered_array_set_in(set, value);
    if (posDeleteElement != set->size)
        deleteByPosSaveOrder_(set->data, &set->size, posDeleteElement);
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set setResult = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; i++)
        append_(setResult.data, &setResult.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++)
        unordered_array_set_insert(&setResult, set2.data[i]);


    return setResult;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(
        unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set setResult = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; i++)
        if (linearSearch_(set2.data, set2.size, set1.data[i]) != set2.size)
            unordered_array_set_insert(&setResult, set1.data[i]);

    return setResult;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(
        unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set setResult = unordered_array_set_create(set1.capacity);
    for (size_t i = 0; i < set1.size; i++)
        if (linearSearch_(set2.data, set2.size, set1.data[i]) == set2.size)
            unordered_array_set_insert(&setResult, set1.data[i]);

    return setResult;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(
        unordered_array_set set1, unordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    unordered_array_set setDeff1 = unordered_array_set_difference(set1, set2);
    unordered_array_set setDeff2 = unordered_array_set_difference(set2, set1);
    unordered_array_set setRes = unordered_array_set_union(setDeff1, setDeff2);

    unordered_array_set_delete(setDeff1);
    unordered_array_set_delete(setDeff2);

    return setRes;
}

// возвращает дополнение до универсума universumSet множества set
unordered_array_set unordered_array_set_complement(
        unordered_array_set set, unordered_array_set universumSet) {
    return unordered_array_set_difference(universumSet, set);
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}");
}

// возвращает значение 'истина',если множество subset
// является подмножеством множества set, иначе - 'ложь'
bool unordered_array_set_isSubset(unordered_array_set subSet,
                                  unordered_array_set set) {
    assert(subSet.capacity == set.capacity);
    for (size_t i = 0; i < subSet.size; i++)
        if (linearSearch_(set.data, set.size, subSet.data[i]) == set.size)
            return false;
    return true;
}

#endif //COURSE_UNORDERED_ARRAY_SET_H
