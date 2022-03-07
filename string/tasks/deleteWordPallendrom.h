#ifndef MAIN_C_DELETEWORDPALLENDROM_H
#define MAIN_C_DELETEWORDPALLENDROM_H

void deleteWordPallendrom(char *s) {
    char *pread = s;
    char *precord = s;
    char *size = getEndOfString(s);
    WordDescriptor word1;
    while (pread != size && getWord(pread, &word1)) {
        pread = word1.end;
        if (!isPallendrom(word1)) {
            precord = copy(word1.begin, word1.end, precord);
            *precord = ' ';
            precord++;
        }
    }

    *precord = '\0';
}

#endif //MAIN_C_DELETEWORDPALLENDROM_H
