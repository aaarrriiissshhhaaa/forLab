#ifndef MAIN_C_DIGITTOSTART_H
#define MAIN_C_DIGITTOSTART_H

#include "../string_.h"
#include <stdio.h>
#include <ctype.h>


void digitToStartReverWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStartReverWord(word);

        beginSearch = word.end;
    }
}

#endif //MAIN_C_DIGITTOSTART_H