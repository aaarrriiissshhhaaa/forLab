#ifndef MAIN_C_REMOVEEXTRASPACES_H
#define MAIN_C_REMOVEEXTRASPACES_H

void removeExtraSpaces(char *s) {
    char *precord = s;
    char symbol = *s;
    while (*s != '\0') {
        if (symbol != ' ' || *s != ' ') {
            *precord = *s;
            precord++;
        }

        symbol = *s;
        s++;
    }

    *precord = '\0';
}


#endif //MAIN_C_REMOVEEXTRASPACES_H
