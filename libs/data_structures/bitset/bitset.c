//
// Created by Lovem on 18.12.2021.
//

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "bitset.h"


#define bitset_base_type  uint32_t

// возвращает пустое множество c универсумом 0, 1,..., maxValue
bitset bitset_create(bitset_base_type maxValue) {
    assert (maxValue < sizeof(bitset_base_type) * 8);
    return (bitset) {0, maxValue};
}

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in(bitset set, bitset_base_type value) {
    return 1 & set.values >> value;
}

// возвращает значение ’истина’, если множества set1 и set2 равны
// иначе - ’ложь’
bool bitset_isEqual(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return set1.values == set2.values;
}

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_isSubset(bitset subset, bitset set) {
    assert(subset.maxValue == set.maxValue);
    return (set.values | subset.values) == set.values;
}

// добавляет элемент value в множество set
void bitset_insert(bitset *set, bitset_base_type value) {
    assert(value >= 0 && value <= set->maxValue);
    set->values |= 1 << value;
}

// удаляет элемент value из множества set
void bitset_deleteElement(bitset *set, bitset_base_type value) {
    set->values &= ~(1 << value);
}

// возвращает объединение множеств set1 и set2
bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values,
                     set1.maxValue};
}

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

// возвращает разность множеств set1 и set2
bitset bitset_difference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & ~set2.values, set1.maxValue};
}

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return bitset_union(bitset_difference(set1, set2), bitset_difference(set2, set1));
}

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set) {
    bitset_base_type unusedBits = (sizeof(bitset_base_type) * 8 - set.maxValue);
    return (bitset) {(~set.values << unusedBits) >> unusedBits, set.maxValue};
}


// вывод множества set
void bitset_print(bitset set) {
    printf("{");
    bool isEmpty = true;
    for (int i = 0; i <= set.maxValue; i++)
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = false;
        }


    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

