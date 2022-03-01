#ifndef MAIN_C_DIGITSPACE_H
#define MAIN_C_DIGITSPACE_H

#include "../string_.h"

void getDigitCountSpace(char *s) {
    char *end = getEndOfString(s);
    char *beginB =  _stringBuffer;
    char *endOfBuffer = copy(s, end, beginB);
    *endOfBuffer = '\0';

    while (*beginB != '\0') {
        if (isalpha(*beginB) || isspace(*beginB)) {
            *s = *beginB;
            s++;
        } else if (isdigit(*beginB)) {
            unsigned char digit = *beginB - '0';
            while (digit--){
                *s = ' ';
                s++;
            }
        }

        beginB++;
    }

    *s = '\0';
}

#endif //MAIN_C_DIGITSPACE_H
