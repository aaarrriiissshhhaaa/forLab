#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include <stdlib.h>
#include <float.h>

double ffabs(const double x) {
    return x > 0 ? x : -x;
}

int isEqual(const float x, const float y) {
    return ffabs(x - y) < FLT_EPSILON;
}

void test_createVector_ZeroCapacityInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(v.data == NULL);
    assert(v.size == 0);
    assert(v.capacity == 0);

    deleteVectorV(&v);
}

void test_createVector_NotZeroCapacityInt() {
    vectorVoid v = createVectorV(2, sizeof(int));

    assert(v.size == 0);
    assert(v.capacity == 2);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_createVectorInt() {
    test_createVector_ZeroCapacityInt();
    test_createVector_NotZeroCapacityInt();
}

void test_reserve_FromZeroToZeroInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    reserveV(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_reserve_FromZeroToNotZeroInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    reserveV(&v, 2);

    assert(v.capacity == 2);
    assert(v.size == 0);
    assert(v.data != NULL);

    deleteVectorV(&v);
}

void test_reserve_FromNotZeroToZeroInt() {
    vectorVoid v = createVectorV(2, sizeof(int));

    reserveV(&v, 0);

    assert(v.capacity == 0);
    assert(v.size == 0);
    assert(v.data == NULL);

    deleteVectorV(&v);
}

void test_reserve_toLesserInt() {
    vectorVoid v = createVectorV(2, sizeof(int));

    int a[] = {1, 2, 3, 4};

    int size = sizeof(a)/sizeof(int);
    for (int i = 0; i < size; i++)
        pushBackV(&v, a + i);

    reserveV(&v, 2);

    assert(v.capacity == 2);
    assert(v.size == 2);
    assert(v.data != NULL);

    for (int i = 0; i < v.size; i++) {
        int elem;
        getVectorValueV(&v, i, &elem);
        assert(elem == a[i]);
    }

    deleteVectorV(&v);
}

void test_reserve_toMoreInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int a[] = {1, 2, 3, 4, 5};

    int size = sizeof(a)/sizeof(int);
    for (int i = 0; i < size; i++)
        pushBackV(&v, a + i);

    reserveV(&v, 10);

    assert(v.capacity == 10);
    assert(v.size == 5);
    assert(v.data != NULL);

    for (int i = 0; i < v.size; i++) {
        int elem;
        getVectorValueV(&v, i, &elem);
        assert(elem == a[i]);
    }

    deleteVectorV(&v);
}

void test_reserveInt() {
    test_reserve_FromZeroToZeroInt();
    test_reserve_FromNotZeroToZeroInt();
    test_reserve_toLesserInt();
    test_reserve_FromZeroToNotZeroInt();
    test_reserve_toMoreInt();
}

void test_shrinkToFit_toZeroInt() {
    vectorVoid v = createVectorV(2, sizeof(int));

    shrinkToFitV(&v);

    assert(v.capacity == 0);
    assert(v.size == 0);

    deleteVectorV(&v);
}

void test_shrinkToFit_toNotZeroInt() {
    vectorVoid v = createVectorV(2, sizeof(int));

    for (int i = 0; i < 3; i++)
        pushBackV(&v, &i);

    shrinkToFitV(&v);

    assert(v.capacity == 3);
    assert(v.size == 3);

    deleteVectorV(&v);
}

void test_shrinkToFitInt() {
    test_shrinkToFit_toZeroInt();
    test_shrinkToFit_toNotZeroInt();
}

void test_pushBack_emptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int elem = 8;
    pushBackV(&v, &elem);

    assert(v.size == 1);
    assert(v.capacity == 1);

    getVectorValueV(&v, 0, &elem);

    assert(elem == 8);

    deleteVectorV(&v);
}

void test_pushBack_fullVectorInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < v.capacity; i++) {
        pushBackV(&v, a + i);
    }

    assert(v.size == 5);

    int elem = 6;
    pushBackV(&v, &elem);

    getVectorValueV(&v, v.size - 1, &elem);
    assert(elem == 6);
    assert(v.size == 6);
    assert(v.capacity == 10);

    deleteVectorV(&v);
}

void test_pushBackInt() {
    test_pushBack_emptyVectorInt();
    test_pushBack_fullVectorInt();
}

void test_popBack_notEmptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int elem = 1;
    pushBackV(&v, &elem);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVectorV(&v);
}

void test_popBackInt() {
    test_popBack_notEmptyVectorInt();
}

void test_getVectorValue_lastElementInt() {
    vectorVoid v = createVectorV(5, sizeof(int));
    int a[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < v.capacity; i++)
        pushBackV(&v, a + i);

    int elem;
    getVectorValueV(&v, v.size - 1, &elem);
    assert(elem == 4);

    deleteVectorV(&v);
}

void test_getVectorValueInt() {
    test_getVectorValue_lastElementInt();
}

void test_isEmpty_emptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isEmpty_notEmptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int elem = 7;
    pushBackV(&v, &elem);

    assert(!isEmptyV(&v));

    deleteVectorV(&v);
}

void test_isFull_emptyVectorInt() {
    vectorVoid v = createVectorV(0, sizeof(int));

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_isFull_notEmptyNotFullVectorInt() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int elem = 2;
    pushBackV(&v, &elem);

    assert(!isFullV(&v));

    deleteVectorV(&v);
}

void test_isFull_FullVectorInt() {
    vectorVoid v = createVectorV(3, sizeof(int));

    int elem = 2;
    pushBackV(&v, &elem);
    pushBackV(&v, &elem);
    pushBackV(&v, &elem);

    assert(isFullV(&v));

    deleteVectorV(&v);
}

void test_isEmptyInt() {
    test_isEmpty_emptyVectorInt();
    test_isEmpty_notEmptyVectorInt();
}

void test_isFullInt() {
    test_isFull_emptyVectorInt();
    test_isFull_notEmptyNotFullVectorInt();
    test_isFull_FullVectorInt();
}

void testInt() {
    test_createVectorInt();
    test_pushBackInt();
    test_popBackInt();
    test_getVectorValueInt();
    test_isEmptyInt();
    test_isFullInt();
    test_reserveInt();
    test_shrinkToFitInt();
}

void testVoid() {
    testInt();
}

int main() {
    testVoid();
}