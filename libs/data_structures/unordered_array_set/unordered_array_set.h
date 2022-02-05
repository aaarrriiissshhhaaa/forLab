//
// Created by Lovem on 19.12.2021.
//

#ifndef COURSE_UNORDERED_ARRAY_SET_H
#define COURSE_UNORDERED_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"

#define unordered_array_set_base_type  int

typedef struct unordered_array_set {
    unordered_array_set_base_type *data;    // элементы множества
    size_t size;                            // количество элементов в множестве
    size_t capacity;                        // максимальное количество элементов в множестве
} unordered_array_set;

// возвращает пустое множество для capacity элементов
unordered_array_set unordered_array_set_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size,
// с максимальным количеством элементов capasity
unordered_array_set unordered_array_set_create_from_array(
        const unordered_array_set_base_type *a, size_t size, size_t capacity);

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t unordered_array_set_in(unordered_array_set *set, unordered_array_set_base_type value);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool unordered_array_set_isEqual(
        unordered_array_set set1, unordered_array_set set2);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void unordered_array_set_isAbleAppend(unordered_array_set *set);

// добавляет элемент value в множество set
void unordered_array_set_insert(
        unordered_array_set *set, unordered_array_set_base_type value);

// возвращает значение 'истина',если множество subset
// является подмножеством множества set, иначе - 'ложь'
bool unordered_array_set_isSubset(unordered_array_set subSet,
                                  unordered_array_set set);

// удаляет элемент value из множества set
void unordered_array_set_deleteElement(
        unordered_array_set *set, unordered_array_set_base_type value);

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(
        unordered_array_set set1, unordered_array_set set2);

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(
        unordered_array_set set1, unordered_array_set set2);

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(
        unordered_array_set set1, unordered_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(
        unordered_array_set set1, unordered_array_set set2);

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(
        unordered_array_set set, unordered_array_set universumSet);

// вывод множества set
void unordered_array_set_print(unordered_array_set set);

// освобождает память, занимаемую множеством set
void unordered_array_set_delete(unordered_array_set set);

#endif //COURSE_UNORDERED_ARRAY_SET_H
