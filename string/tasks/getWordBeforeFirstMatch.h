#ifndef MAIN_C_GETWORDBEFOREFIRSTMATCH_H
#define MAIN_C_GETWORDBEFOREFIRSTMATCH_H

#include "../string_.h"

typedef enum WordBeforeWordReturnCode {
    FIRST_WORD,
    NOT_FOUND_WORD,
    BEFORE_WORD_FOUND,
    EMPTY_STR
} WordBeforeWordReturnCode;

WordBeforeWordReturnCode getWordBeforeFirstMatch(char *s1, char *s2, WordDescriptor *word) {
    getBagOfWords(&_bag1, s1);
    getBagOfWords(&_bag2, s2);

    if (_bag1.size == 0)
        return EMPTY_STR;

    if (_bag2.size == 0)
        return NOT_FOUND_WORD;

    int wordFound;
    int isFound = false;
    for (int i = 0; i < _bag1.size; i++) {
        for (int j = 0; j < _bag2.size && !isFound; j++) {
            isFound = areWordsEqual(_bag1.words[i], _bag2.words[j]);
            if(isFound)
                wordFound = i;
        }

        if (isFound)
            if (wordFound == 0)
                return FIRST_WORD;
            else {
                *word = _bag1.words[wordFound - 1];
                return BEFORE_WORD_FOUND;
            }
    }

    return NOT_FOUND_WORD;
}

#endif //MAIN_C_GETWORDBEFOREFIRSTMATCH_H
