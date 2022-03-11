#ifndef MAIN_C_REVERSEWORDINSTRING_H
#define MAIN_C_REVERSEWORDINSTRING_H
#include "../../libs/algorithms/algorithm.h"

void reverseWord(WordDescriptor word) {
    if(*word.end == ' ' || *word.end == '\0')
        word.end--;

    char* b = word.begin;
    char* e = word.end;
    while(b != e && b < e){
        char tmp = *e;
        *e = *b;
        *b = tmp;
        b++;
        e--;
    }
}

void reverseWordInString(char *s) {
    char *beginSearch = s;
    WordDescriptor word;

    while (getWord(beginSearch, &word)) {
        reverseWord(word);

        beginSearch = word.end;
    }
}


#endif //MAIN_C_REVERSEWORDINSTRING_H
