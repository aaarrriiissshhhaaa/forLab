#ifndef MAIN_C_WORDSOFEQUALLETTERS_H
#define MAIN_C_WORDSOFEQUALLETTERS_H

#include "../string_.h"

int cmpChar(void *a, void *b) {
    return *((char *) a) -*((char *) b);
}

#include "areTheSameWordsInString.h"

int wordsOfEqualLetters(char *s) {
    copy(s, s + strlen_(s) + 1, _stringBuffer);

    getBagOfWords(&_bag1, _stringBuffer);
    for (int i = 0; i < _bag1.size; i++)
        qsort(_bag1.words[i].begin, _bag1.words[i].end - _bag1.words[i].begin,
              sizeof(char), cmpChar);

    return areTheSameWordsInString(_stringBuffer);
}

#endif //MAIN_C_WORDSOFEQUALLETTERS_H
