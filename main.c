#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

    deleteVector(&v);

}

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    assert (v.data[0] == 10);
    assert (v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 1);

    assert(v.size == 2);
    assert (v.data[1] == 1);
    assert (v.capacity == 2);

    deleteVector(&v);
}

void test_atVector_notEmptyVector(){
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    int * index2 = atVector(&v, 1);

    assert(*index2 == 2);

    deleteVector(&v);
}

void test_atVector_requestToLastElement(){
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    int * index2 = atVector(&v, 2);

    assert(*index2 == 3);

    deleteVector(&v);
}

void test_atVector_requestToFirstElement(){
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    int * index2 = atVector(&v, 0);

    assert(*index2 == 1);

    deleteVector(&v);
}

void test_back_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 1);

    int * index2 = back(&v);

    assert(*index2 == 1);

    deleteVector(&v);
}

void test_front_oneElementInVector(){
    vector v = createVector(1);
    pushBack(&v, 1);

    int * index2 = front(&v);

    assert(*index2 == 1);

    deleteVector(&v);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_atVector_requestToFirstElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    return 0;
}