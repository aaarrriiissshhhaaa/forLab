#ifndef MAIN_C_STRING__H
#define MAIN_C_STRING__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];


#define  ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__ , __FUNCTION__ , __LINE__ )

typedef struct WordDescriptor {
    char *begin;   // позиция начала слова
    char *end;     // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

size_t strlen_(const char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

int getWord(char *beginSearch, WordDescriptor *word);

char *copyNonIfReverse(char *rbeginSource, const char *rendSource,
                       char *beginDestination, int (*f)(int));

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

int getOrderTwoWord(WordDescriptor w1, WordDescriptor w2);

int getWordSeparatedByCommas(char *beginSearch, WordDescriptor *word);

void getBagOfWords(BagOfWords *bag, char *s);
void selectionSortLettersWord(WordDescriptor *a);

#endif //MAIN_C_STRING__H
