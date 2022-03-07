#ifndef MAIN_C_COUNTPALLENDROM_H
#define MAIN_C_COUNTPALLENDROM_H

#include "../string_.h"
#include "stdbool.h"
#include "iso646.h"

bool isPallendrom(WordDescriptor w) {
    w.end--;
    while (w.begin < w.end) {
        if (*w.begin != *w.end)
            return false;
        else {
            w.begin++;
            w.end--;
        }
    }

    return true;
}


// работает только для строки с одинаковым регистром
int getCountPallendrom(char *s) {
    WordDescriptor w;
    int cntP = 0;
    while (*s and getWordSeparatedByCommas(s, &w)) {
        cntP += isPallendrom(w);
        s = w.end;
    }

    return cntP;
}

#endif //MAIN_C_COUNTPALLENDROM_H
