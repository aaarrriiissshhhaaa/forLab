#ifndef MAIN_C_GETLASTWORDFROMFIRSTTOSECOND_H
#define MAIN_C_GETLASTWORDFROMFIRSTTOSECOND_H

#include "../string_.h"

WordDescriptor getLastWordFromFirstToSecond(char *s1, char *s2) {
    getBagOfWords(&_bag1, s1);
    getBagOfWords(&_bag2, s2);

    if (!_bag2.size) {
        return (WordDescriptor) {NULL, NULL};
    }

    int lastWord = -1;
    for (int i = 0; i < _bag1.size; i++) {
        bool isEqual = false;
        for (int j = 0; j < _bag2.size && !isEqual; j++)
            isEqual = areWordsEqual(_bag1.words[i], _bag2.words[j]);

        if (isEqual)
            lastWord = i;
    }

    if (lastWord == -1)
        return (WordDescriptor) {NULL, NULL};
    else
        return _bag1.words[lastWord];
}

void wordDescriptorToString(WordDescriptor w, char *s) {
    if (w.begin == NULL || *w.begin == '\0')
        *s = '\0';
    else

        *copy(w.begin, w.end, s) = '\0';

}

#endif //MAIN_C_GETLASTWORDFROMFIRSTTOSECOND_H
