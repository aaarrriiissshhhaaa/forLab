#ifndef MAIN_C_ADDTOTHESTRINGWITHLESSWORD_H
#define MAIN_C_ADDTOTHESTRINGWITHLESSWORD_H

#include "../string_.h"

void additionalEntry(char *s, BagOfWords bag, size_t size1, size_t size2) {
    for (int i = size1; i < size2; i++) {
        *s++ = ' ';
        s = copy(bag.words[i].begin, bag.words[i].end, s);
    }
}

void addToTheStringWithLessWord(char *s1, char *s2) {
    getBagOfWords(&_bag1, s1);
    getBagOfWords(&_bag2, s2);

    if (_bag1.size == _bag2.size)
        return;

    char *sRecord;
    if (_bag1.size < _bag2.size) {
        sRecord = findNonSpaceReverse(s1 + strlen_(s1) - 1, s1) + 1;
        for (int i = _bag1.size - 1; i < _bag2.size; i++) {
            *sRecord = ' ';
            sRecord++;
            sRecord = copy(_bag2.words[i].begin, _bag2.words[i].end, sRecord);
        }
    } else {
        sRecord = findNonSpaceReverse(s2 + strlen_(s2) - 1, s2) + 1;
        for (int i = _bag2.size - 1; i < _bag1.size; i++) {
            *sRecord = ' ';
            sRecord++;
            sRecord = copy(_bag1.words[i].begin, _bag1.words[i].end, sRecord);
        }
    }
    *sRecord = '\0';
}

#endif //MAIN_C_ADDTOTHESTRINGWITHLESSWORD_H
