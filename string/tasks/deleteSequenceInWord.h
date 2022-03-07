#ifndef MAIN_C_DELETESEQUENCEINWORD_H
#define MAIN_C_DELETESEQUENCEINWORD_H

#include "../string_.h"

void deleteSequenceInWord(char *str, char *seque) {
    WordDescriptor word;
    char *endSeque = getEndOfString(seque);
    char *endStr = getEndOfString(str);
    char *pread = str;
    char *precord = str;
    while (pread != endStr && getWord(pread, &word)) {
        char *beginW = word.begin;
        while (beginW != word.end and *beginW != *seque)
            beginW++;
        bool isFirst = true;
        if (beginW != word.end) {
            char *copySeq = seque;
            while (copySeq != endSeque && *beginW == *copySeq) {
                isFirst = false;
                copySeq++;
                beginW++;
            }
            if (copySeq != endSeque) {
                precord = copy(word.begin, word.end, precord);
                *precord = ' ';
                precord++;
            }
        }

        if(isFirst) {
            precord = copy(word.begin, word.end, precord);
            *precord = ' ';
            precord++;
        }

        pread = word.end;
    }

    *precord = '\0';
}

#endif //MAIN_C_DELETESEQUENCEINWORD_H
