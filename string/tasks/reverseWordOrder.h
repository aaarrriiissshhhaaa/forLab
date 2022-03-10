#ifndef MAIN_C_REVERSEWORDORDER_H
#define MAIN_C_REVERSEWORDORDER_H

#include "../string_.h"


//  в начале строки должен быть  ' '
void reverseWordsOrder(char *s) {
    int size = strlen_(s);
    copy(s, s + size + 1, _stringBuffer);
    char *beginSearch = _stringBuffer + size - 1;
    char *endSearch = _stringBuffer - 1;
    char * beginRecord = s;
    WordDescriptor w;
    while (getWordReverse(beginSearch, endSearch, &w)) {
        beginRecord = copy(w.begin, w.end + 1, beginRecord);
        *beginRecord = ' ';
        beginRecord++;
        beginSearch = w.begin - 1;
    }
    --beginRecord;
    *beginRecord = '\0';

}

#endif //MAIN_C_REVERSEWORDORDER_H
