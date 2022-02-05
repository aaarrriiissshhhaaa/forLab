//
// Created by Lovem on 20.12.2021.
//

#ifndef COURSE_ORDERED_ARRAY_SET_H
#define COURSE_ORDERED_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../algorithms/array/array.h"

#define ordered_array_set_base_type  int

typedef struct ordered_array_set {
    ordered_array_set_base_type *data;  // элементы множества
    size_t size;                        // количество элементов в множестве
    size_t capacity;                    // максимальное количество элементов
    // в множестве
} ordered_array_set;

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size
// с максимальным количество элементов capacity
ordered_array_set ordered_array_set_create_from_array(
        const ordered_array_set_base_type *a, size_t size, size_t capacity);

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - SIZE_MAX
size_t ordered_array_set_in(ordered_array_set *set,
                            ordered_array_set_base_type value);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2);

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set);

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set,
                              ordered_array_set_base_type value);

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set,
                                     ordered_array_set_base_type value);

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2);

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set
                                                 set1, ordered_array_set set2);

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set
                                               set1, ordered_array_set set2);

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2);

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set,
                                               ordered_array_set universumSet);

// вывод множества set
void ordered_array_set_print(ordered_array_set set);

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set);

#endif //COURSE_ORDERED_ARRAY_SET_H
