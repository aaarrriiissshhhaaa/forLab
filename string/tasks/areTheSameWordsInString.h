#ifndef MAIN_C_ARETHESAMEWORDSINSTRING_H
#define MAIN_C_ARETHESAMEWORDSINSTRING_H
#include"../string_.h"

int areTheSameWordsInString(char *s) {
    getBagOfWords(&_bag1, s);

    for (int i = 0; i < _bag1.size; i++)
        for (int j = i + 1; j < _bag1.size; j++)
            if (areWordsEqual(_bag1.words[i], _bag1.words[j]) == 1)
                return 1;

    return 0;
}

#endif //MAIN_C_ARETHESAMEWORDSINSTRING_H
