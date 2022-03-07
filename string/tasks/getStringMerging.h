#ifndef MAIN_C_GETSTRINGMERGING_H
#define MAIN_C_GETSTRINGMERGING_H

#include "../string_.h"

void getStringMerging(char *s1, char *s2, char *s) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found and isW2Found) {
            s = copy(word1.begin, word1.end, s);
            *s = ' ';
            s++;
            s = copy(word2.begin, word2.end, s);
        } else if (isW1Found) {
            s = copy(word1.begin, word1.end, s);
        } else {
            s = copy(word2.begin, word2.end, s);
        }
        *s = ' ';
        s++;
        if (*beginSearch1)
            beginSearch1 = word1.end;
        if (*beginSearch2)
            beginSearch2 = word2.end;
    }

    if (s1 != beginSearch1 or s2 != beginSearch2) {
        s--;
    }

    *s = '\0';
}


#endif
