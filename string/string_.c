#include "string_.h"
#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#include "iso646.h"

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
int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

//char *searcWordInStr(char *s1, char *w) {
//    while (*s1) {
//        if (*s1 == *w) {
//            int isСonformity = 1;
//
//            char *beginSearchWord = w;
//            char *beginSearchSource = s1;
//
//            while (*beginSearchWord)
//                if (*beginSearchWord == *beginSearchSource && isСonformity) {
//                    beginSearchWord++;
//                    beginSearchSource++;
//                } else
//                    isСonformity = 0;
//
//            if (isСonformity)
//                return s1;
//        }
//
//        s1++;
//    }
//
//    return s1;
//}




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
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *(beginDestination++) = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}

char *copyNonIfReverse(char *rbeginSource, const char *rendSource,
                       char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (!f(*rbeginSource))
            *(beginDestination++) = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}


// Возвращает указатель на первый ноль символ строки s
char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    int x = strcmp_(expected, got);
    if (x) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

// возвращает истина или ложь при наличии слова изменяет слово
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);
    return 1;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (word->end == rend || *word->end == '\0')
        return 0;

    word->begin = findSpaceReverse(word->end, rend);
    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2){
    if(w1.end - w1.begin != w2.end - w2.begin)
        return 0;

    while(w1.begin != w1.end){
        if(*w1.begin == *w2.begin){
            w1.begin++;
            w2.begin++;
        }else
            return 0;
    }

    return 1;
}


int getOrderChar(char *w1, char *w2){
    return *w2 - *w1;
}

int getOrderTwoWord(WordDescriptor w1, WordDescriptor w2){
   while (w1.begin != w1.end and w2.begin!=w2.end
            and getOrderChar(w1.begin, w2.begin) >= 0){
       w1.begin++;
       w2.begin++;
   }

   return w1.begin == w1.end or w2.begin == w2.end;

}

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    WordDescriptor word;
    while (getWord(s, &word)) {
        bag->words[bag->size] = word;

        bag->size++;
        s = word.end;
    }
}
