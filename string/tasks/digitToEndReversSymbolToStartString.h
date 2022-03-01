#ifndef MAIN_C_DIGITTOENDREVERSSYMBOLTOSTARTSTRING_H
#define MAIN_C_DIGITTOENDREVERSSYMBOLTOSTARTSTRING_H

#include "../string_.h"
#include <stdio.h>
#include <ctype.h>

void digitToEndReversSymbolToStartWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIf(_stringBuffer - 1,
                               endStringBuffer,
                               word.begin, isalpha);
    copyIfReverse(endStringBuffer - 1, _stringBuffer - 1,
                  recPosition, isdigit);
}

void digitToEndReversSymbolToStartString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToEndReversSymbolToStartWord(word);

        beginSearch = word.end;
    }
}

#endif //MAIN_C_DIGITTOENDREVERSSYMBOLTOSTARTSTRING_H
