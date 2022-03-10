#ifndef MAIN_C_REVERSEWORDS_H
#define MAIN_C_REVERSEWORDS_H

#include "../string_.h"

void reverseWords(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';

    getBagOfWords(&_bag1, _stringBuffer);

    char *beginDist = s;
    for (int i = _bag1.size - 1; i >= 0; i--) {
        beginDist = copy(_bag1.words[i].begin, _bag1.words[i].end, beginDist);
        *beginDist = ' ';
        beginDist++;
    }

    if (_bag1.size != 0)
        beginDist--;

    *beginDist = '\0';
}

#endif //MAIN_C_REVERSEWORDS_H
