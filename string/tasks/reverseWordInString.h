#ifndef MAIN_C_REVERSEWORDINSTRING_H
#define MAIN_C_REVERSEWORDINSTRING_H

void reverseWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyNonIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isspace);
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
