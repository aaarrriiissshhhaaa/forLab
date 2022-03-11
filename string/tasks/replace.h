#ifndef MAIN_C_REPLACE_H
#define MAIN_C_REPLACE_H

#include "../string_.h"

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        *copy(source, getEndOfString(source), _stringBuffer) = '\0';
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor cur_word;
    while (getWord(readPtr, &cur_word)) {
        recPtr = copy(readPtr, cur_word.begin, recPtr);
        if (areWordsEqual(cur_word, word1))
            recPtr = copy(word2.begin, word2.end, recPtr);
        else
            recPtr = copy(cur_word.begin, cur_word.end,
                          recPtr);

        readPtr = cur_word.end;
    }
    *recPtr = '\0';
}



#endif //MAIN_C_REPLACE_H
