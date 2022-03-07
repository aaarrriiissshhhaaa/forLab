#ifndef MAIN_C_ISORDERWORD_H
#define MAIN_C_ISORDERWORD_H

#include "../string_.h"
#include "iso646.h"


// работает только для строк с одинаковым регистром.
bool isOrderWordInStr(char *s) {
    WordDescriptor w1;
    if (!getWord(s, &w1))
        return true;
    WordDescriptor w2;
    while (*s and getWord(s, &w2)) {
        if (getOrderTwoWord(w1, w2)) {
            w1 = w2;
            s = w2.end;
        }
        else
            return 0;
    }

    return 1;
}

#endif //MAIN_C_ISORDERWORD_H
