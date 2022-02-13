#include "algorithm.h"
#include <stdio.h>
#include <stdlib.h>

void swap(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char tmp = *pa;
        *pa = *pb;
        *pb = tmp;
        pa += 1;
        pb += 1;
    }
}