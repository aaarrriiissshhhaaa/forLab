#ifndef MAIN_C_GETWORDBEFOREFIRSTWORDWITHA_H
#define MAIN_C_GETWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore,
                                                               char **endWordBefore) {
    WordDescriptor wordFirst;
    if (!getWord(s, &wordFirst))
        return EMPTY_STRING;

    else if (find(wordFirst.begin, wordFirst.end, 'A') != wordFirst.end
             || find(wordFirst.begin, wordFirst.end, 'a') != wordFirst.end)

        return FIRST_WORD_WITH_A;

    char *begin = wordFirst.end;
    WordDescriptor wordCur;
    while (getWord(begin, &wordCur)) {
        if (find(wordCur.begin, wordCur.end, 'A') != wordCur.end
            || find(wordCur.begin, wordCur.end, 'a') != wordCur.end) {
            *beginWordBefore = wordFirst.begin;
            *endWordBefore = wordFirst.end;

            return WORD_FOUND;
        }
        wordFirst = wordCur;
        begin = wordCur.end;
    }

    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    char *beginWordBefore, *endWordBefore;

    if (getWordBeforeFirstWordWithA(begin, &beginWordBefore, &endWordBefore) == WORD_FOUND) {
        *endWordBefore = '\0';

        printf("%s", beginWordBefore);
    }
}

#endif

