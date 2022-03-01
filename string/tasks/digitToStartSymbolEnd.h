#ifndef MAIN_C_DIGITTOSTARTSYMBOLEND_H
#define MAIN_C_DIGITTOSTARTSYMBOLEND_H

#include "../string_.h"
#include <stdio.h>
#include <ctype.h>

void digitToEndSymbolToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIf(_stringBuffer - 1,
                               endStringBuffer,
                               word.begin, isalpha);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);
}

void digitToEndSymbolToStartString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        digitToEndSymbolToStart(word);

        beginSearch = word.end;
    }
}


#endif //MAIN_C_DIGITTOSTARTSYMBOLEND_H
