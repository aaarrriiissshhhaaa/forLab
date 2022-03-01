#ifndef MAIN_C_DIGITTOSTARTNONREVERSSTRING_H
#define MAIN_C_DIGITTOSTARTNONREVERSSTRING_H


#include "../string_.h"
#include <stdio.h>
#include <ctype.h>


void digitToStartNonReverWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIf(_stringBuffer - 1,
                               endStringBuffer,
                               word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartNonReversString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToStartNonReverWord(word);

        beginSearch = word.end;
    }
}


#endif //MAIN_C_DIGITTOSTARTNONREVERSSTRING_H
