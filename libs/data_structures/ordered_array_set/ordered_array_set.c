//
// Created by Lovem on 20.12.2021.
//

#ifndef COURSE_ORDERED_ARRAY_SET_H
#define COURSE_ORDERED_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#include "../../algorithms/array/array.h"

#define ordered_array_set_base_type  int

typedef struct ordered_array_set {
    ordered_array_set_base_type *data;  // элементы множества
    size_t size;                        // количество элементов в множестве
    size_t capacity;                    // максимальное количество элементов
    // в множестве
} ordered_array_set;

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof
                                       (ordered_array_set_base_type *) * capacity), 0, capacity};
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - SIZE_MAX
size_t ordered_array_set_in(ordered_array_set *set,
                            ordered_array_set_base_type value) {
    return binarySearch_(set->data, set->size, value);
}


// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set,
                              ordered_array_set_base_type value) {
    ordered_array_set_isAbleAppend(set);
    if (set->size == 0) {
        insert_(set->data, &set->size, 0, value);
    } else if (ordered_array_set_in(set, value) == SIZE_MAX)
        insert_(set->data, &set->size,
                binarySearchMoreOrEqual_(set->data, set->size, value), value);
}

// возвращает множество, состоящее из элементов массива a размера size
// с максимальным количество элементов capacity
ordered_array_set ordered_array_set_create_from_array(
        const ordered_array_set_base_type *a, size_t size, size_t capacity) {

    ordered_array_set setResult = ordered_array_set_create(capacity);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&setResult, a[i]);

    return setResult;
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    if (set1.size != set2.size)
        return false;
    else {
        size_t set2Read = 0;
        for (size_t set1Read = 0; set1Read < set1.size; set1Read++)
            if (set1.data[set1Read] != set2.data[set2Read++])
                return false;
        return true;
    }
}

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool ordered_array_set_isSubset(ordered_array_set subset,
                                ordered_array_set set) {
    assert(set.capacity == subset.capacity);
    if(subset.size == 0)
        return true;
    size_t setRead = 0;
    size_t subsetRead = 0;
    if (set.data[setRead] > subset.data[subsetRead])
        return false;
    while (set.data[setRead] < subset.data[subsetRead])
        setRead++;
    for (size_t subsetReadFor = subsetRead; setRead < set.size && subsetRead < subset.size; subsetRead++)
        if (set.data[setRead] == subset.data[subsetRead]) {
            setRead++;
            subsetRead++;
        } else if (set.data[setRead] > subset.data[subsetRead])
            return false;
        else
            setRead++;

    if (subsetRead == subset.size)
        return true;
    else
        return false;
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set,
                                     ordered_array_set_base_type value) {
    size_t posDelete = ordered_array_set_in(set, value);
    if (posDelete != SIZE_MAX)
        deleteByPosSaveOrder_(set->data, &set->size, posDelete);
}


// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    ordered_array_set setResult = ordered_array_set_create(set1.capacity);
    size_t set1Read = 0;
    size_t set2Read = 0;

    while (set1Read < set1.size && set2Read < set2.size) {
        if (set1.data[set1Read] < set2.data[set2Read])
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
        else if (set1.data[set1Read] > set2.data[set2Read])
            append_(setResult.data, &setResult.size, set2.data[set2Read++]);
        else {
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
            set2Read++;
        }
    }

    while (set1Read < set1.size)
        append_(setResult.data, &setResult.size, set1.data[set1Read++]);
    while (set2Read < set2.size)
        append_(setResult.data, &setResult.size, set2.data[set2Read++]);

    return setResult;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1,
                                                 ordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    ordered_array_set setResult = ordered_array_set_create(set1.capacity);
    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size) {
        if (set1.data[set1Read] < set2.data[set2Read])
            set1Read++;
        else if (set1.data[set1Read] > set2.data[set2Read])
            set2Read++;
        else {
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
            set2Read++;
        }
    }

    return setResult;
}


// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1,
                                               ordered_array_set set2) {
    assert(set1.capacity == set2.capacity);
    ordered_array_set setResult = ordered_array_set_create(set1.capacity);
    size_t set1Read = 0;
    size_t set2Read = 0;
    while (set1Read < set1.size && set2Read < set2.size) {
        if (set1.data[set1Read] < set2.data[set2Read])
            append_(setResult.data, &setResult.size, set1.data[set1Read++]);
        else if (set1.data[set1Read] > set2.data[set2Read])
            set2Read++;
        else {
            set1Read++;
            set2Read++;
        }
    }
    while (set1Read < set1.size)
        append_(setResult.data, &setResult.size, set1.data[set1Read++]);

    return setResult;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set setDeff1 = ordered_array_set_difference(set1, set2);
    ordered_array_set setDeff2 = ordered_array_set_difference(set2, set1);
    ordered_array_set setResult = ordered_array_set_union(setDeff1, setDeff2);

    ordered_array_set_delete(setDeff1);
    ordered_array_set_delete(setDeff2);

    return setResult;
}

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set,
                                               ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++)
        printf("%d, ", set.data[i]);
    if (set.size == 0)
        printf("}");
    else
        printf("\b\b}");
}


#endif //COURSE_ORDERED_ARRAY_SET_H