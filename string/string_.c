#include "string_.h"
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>


// возвращает количество символов в строке begin
size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

// возвращает указатель на первый элемент с кодом ch
// расположенным на ленте памяти между begin и end.
// Если символ не найден возвращает end
char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

// возвращает указатель на первый символ отличных от пробелных
// расположенным на ленте памяти между begin и заканчивая ноль-символом.
// Если символ не найден возвращает адресс первого ноль-символа.
char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

// возвращает указатель на первый пробельный символ
// расположенным на ленте памяти между begin и заканчивая ноль-символом.
// Если символ не найден возвращает адресс первого ноль-символа.
char *findSpace(char *begin) {
    while (*begin != '\0' && !(isspace(*begin)))
        begin++;

    return begin;
}

// возвращает указатель на первый справа символ, отличных от пробельных
// расположенным на ленте памяти между rbegin и заканчивая rend.
// Если символ не найден возвращает адресс rend.
char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

// возвращает указатель на первый пробельный символ справа,
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// Если символ не найден, возвращает адрес rend
char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !(isspace(*rbegin)))
        rbegin--;

    return rbegin;
}

// возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}


// Возвращает указатель на следующий свободный фрагмент памяти в
// destination. Записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса beginSource до endSource
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

// Возвращает указатель на следующий свободный фрагмент памяти в
// destination. Записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса beginSource до endSource
// все элементы удовлетворяющие функции-предикату f
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *(beginDestination++) = *beginSource;

        beginSource++;
    }

    return beginDestination;
}


// Возвращает указатель на следующий свободный фрагмент памяти в
// destination. Записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса rendSource до rbeginSource
// все элементы удовлетворяющие функции-предикату f
char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)){
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *(beginDestination++) = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}