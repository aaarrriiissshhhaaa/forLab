#ifndef MAIN_C_DELETEEQUALLASTWORD_H
#define MAIN_C_DELETEEQUALLASTWORD_H

#include "../string_.h"

void deleteEqualLastWord(char *s) {
    int size = strlen_(s);
    char *copyS = s;
    WordDescriptor word;
    getWordReverse(&copyS[size - 1], s, &word);

    char *pread = s;
    char *precord = s;
    WordDescriptor word1;
    while (*pread && getWord(pread, &word1)) {
        if (!areWordsEqual(word, word1)) {
            precord = copy(word1.begin, word1.end, precord);
            *precord = ' ';
            precord++;
        }
        pread = word1.end;
    }
    *precord = '\0';
}


#endif //MAIN_C_DELETEEQUALLASTWORD_H
