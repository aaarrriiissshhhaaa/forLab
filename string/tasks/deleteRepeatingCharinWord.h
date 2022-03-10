#ifndef MAIN_C_DELETEREPEATINGCHARINWORD_H
#define MAIN_C_DELETEREPEATINGCHARINWORD_H

#include "../string_.h"

void deleteRepeatingCharinWord(char *s) {
    WordDescriptor w;
    char *pread = s;
    char *precord = s;
    while (getWord(pread, &w)) {
        bool isEqual = false;
        for(char *beginW = w.begin; beginW < w.end - 1 && !isEqual; beginW++)
            for (char * beginWW = beginW + 1;beginWW  < w.end && !isEqual; beginWW++) {
                isEqual = *beginWW == *beginW;
            }
        if (!isEqual) {
            precord = copy(w.begin, w.end, precord);
            *precord = ' ';
            precord++;
        }

        pread = w.end;
    }

    *precord = '\0';
}

#endif //MAIN_C_DELETEREPEATINGCHARINWORD_H
