#ifndef MAIN_C_REMOVEADJACENTEQUALLETTERS_H
#define MAIN_C_REMOVEADJACENTEQUALLETTERS_H

void removeAdjacentEqualLetters(char *s) {
    char *precord = s;
    char symbol = *s;
    while (*s != '\0') {
        if (symbol != *s) {
            *precord = symbol;
            precord++;
        }

        symbol = *s;
        s++;
    }

    *precord = symbol;
    precord++;
    *precord = '\0';

}

#endif //MAIN_C_REMOVEADJACENTEQUALLETTERS_H
