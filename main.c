#include <stdio.h>
#include <assert.h>
//#include <string.h>
#include "string/string_.h"
#include <ctype.h>
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeAdjacentEqualLetters.h"
#include "string/tasks/removeExtraSpaces.h"
#include "string/tasks/digitToStart.h"
#include "string/tasks/digitToStartSymbolEnd.h"
#include "string/tasks/digitToEndReversSymbolToStartString.h"
#include "string/tasks/digitToStartNonReversString.h"
#include "string/tasks/reverseWordInString.h"

void test_strlen_fullStr() {
    char a[11] = "ABCDEFGHIJ";

    assert(10 == strlen_(a));
}

void test_strlen_nullStr() {
    char a[11] = "";

    assert(0 == strlen_(a));
}

void test_strlen_oneChSpace() {
    char a[11] = " ";

    assert(1 == strlen_(a));
}

void test_strlen_oneChNonSpace() {
    char a[11] = "a";

    assert(1 == strlen_(a));
}

void test_strlen() {
    test_strlen_fullStr();
    test_strlen_nullStr();
    test_strlen_oneChSpace();
    test_strlen_oneChNonSpace();
}

void test_find_endAndBeginEqual() {
    char a[10] = "abcdefghi";
    char *elTrue = &a[2];
    char *elEx = find(&a[2], &a[2], 'c');

    assert(elTrue == elEx);
}

void test_find_endAndBeginNonEqualSymbolFind() {
    char a[10] = "abcdefghi";
    char *end = &a[2];

    assert(end == find(&a[1], &a[6], 'c'));
}

void test_find_SymbolNotFind() {
    char a[10] = "abcdefghi";
    char *end = &a[8];

    assert(end == find(&a[1], &a[8], ' '));
}


void test_find() {
    test_find_endAndBeginNonEqualSymbolFind();
    test_find_endAndBeginEqual();
    test_find_SymbolNotFind();
}

void test_findNonSpace_strFullSpace() {
    char a[10] = "         ";

    char *end = &a[9];

    assert(end == findNonSpace(a));
}

void test_findNonSpace_strFullSpaceAfterBegin() {
    char a[10] = "a        ";

    char *end = &a[9];

    assert(end == findNonSpace(&a[2]));
}

void test_findNonSpace_strNonOnlySpaceAfterBegin() {
    char a[10] = "a      b ";

    char *end = &a[7];

    assert(end == findNonSpace(&a[2]));
}

void test_findNonSpace_lastElement() {
    char a[10] = "a       b";

    char *end = &a[8];

    assert(end == findNonSpace(&a[2]));
}

void test_findNonSpace_classic() {
    char a[10] = "a       b";

    assert(a == findNonSpace(a));
}

void test_findNonSpace_classicShiftBegin() {
    char a[10] = "a       b";
    char *end = &a[8];

    assert(end == findNonSpace(&a[1]));
}

void test_findNonSpace_classicShiftBeginSpaceEnter() {
    char a[10] = "a   \n   b";
    char *end = &a[8];

    assert(end == findNonSpace(&a[1]));
}

void test_findNonSpace() {
    test_findNonSpace_strFullSpace();
    test_findNonSpace_strFullSpaceAfterBegin();
    test_findNonSpace_strNonOnlySpaceAfterBegin();
    test_findNonSpace_classicShiftBegin();
    test_findNonSpace_classic();
    test_findNonSpace_lastElement();
    test_findNonSpace_classicShiftBeginSpaceEnter();
}

void test_findSpace_notSpaceSymbol() {
    char a[10] = "abcdefghi";

    assert(&a[9] == findSpace(a));
}

void test_findSpace_onlySpaceSymbol() {
    char a[10] = "   \n  \n\n\n";

    assert(a == findSpace(a));
}

void test_findSpace_farRight() {
    char a[10] = "abcdefgh ";

    assert(&a[8] == findSpace(a));
}

void test_findSpace_farRightSpaceEnter() {
    char a[10] = "abcdefgh\n";

    assert(&a[8] == findSpace(a));
}

void test_findSpace_farLeft() {
    char a[10] = " bcdefgh\n";

    assert(a == findSpace(a));
}

void test_findSpace_farLeftSpaceEnter() {
    char a[10] = "\nbcdefghi";

    assert(a == findSpace(a));
}

void test_findSpace_shiftBeginZeroSpace() {
    char a[10] = "\nbcdefghi";

    assert(&a[9] == findSpace(&a[1]));
}

void test_findSpace_shiftBeginFullSpace() {
    char a[10] = "\n        ";

    assert(&a[1] == findSpace(&a[1]));
}

void test_findSpace_shiftBeginSpaceEnter() {
    char a[10] = "\nbcdefg\ni";

    assert(&a[7] == findSpace(&a[1]));
}

void test_findSpace() {
    test_findSpace_notSpaceSymbol();
    test_findSpace_onlySpaceSymbol();
    test_findSpace_farRight();
    test_findSpace_farRightSpaceEnter();
    test_findSpace_farLeft();
    test_findSpace_farLeftSpaceEnter();
    test_findSpace_shiftBeginZeroSpace();
    test_findSpace_shiftBeginFullSpace();
    test_findSpace_shiftBeginSpaceEnter();
}

void test_findNonSpaceReverse_notSpaceSymbol() {
    char a[10] = "abcdefghi";

    assert(&a[8] == findNonSpaceReverse(&a[8], a));
}

void test_findNonSpaceReverse_endAndBeginNonEquaNotSpaceLast() {
    char a[10] = "ab       ";

    assert(&a[1] == findNonSpaceReverse(&a[8], a));
}

void test_findNonSpaceReverse_endAndBeginEqualSpace() {
    char a[10] = "ab      \n";

    assert(&a[8] == findNonSpaceReverse(&a[8], &a[8]));
}

void test_findNonSpaceReverse_endAndBeginEqualNonSpace() {
    char a[10] = "ab      i";

    assert(&a[8] == findNonSpaceReverse(&a[8], &a[8]));
}

void test_findNonSpaceReverse_farRightRend() {
    char a[10] = "abc     \n";

    assert(&a[2] == findNonSpaceReverse(&a[8], &a[1]));
}

void test_findNonSpaceReverse_classic() {
    char a[10] = "abc c   \n";

    assert(&a[4] == findNonSpaceReverse(&a[8], &a[1]));
}

void test_findNonSpaceReverse() {
    test_findNonSpaceReverse_notSpaceSymbol();
    test_findNonSpaceReverse_endAndBeginNonEquaNotSpaceLast();
    test_findNonSpaceReverse_endAndBeginEqualSpace();
    test_findNonSpaceReverse_endAndBeginEqualNonSpace();
    test_findNonSpaceReverse_farRightRend();
    test_findNonSpaceReverse_classic();
}

void test_findSpaceReverse_notSpaceSymbol() {
    char a[10] = "abcdefghi";

    assert(a == findSpaceReverse(&a[8], a));
}

void test_findSpaceReverse_endAndBeginNonEqualSpaceLast() {
    char a[10] = " bcdefghi";

    assert(a == findSpaceReverse(&a[8], a));
}

void test_findSpaceReverse_endAndBeginEqualSpace() {
    char a[10] = "abcdefgh ";

    assert(&a[8] == findSpaceReverse(&a[8], &a[8]));
}

void test_findSpaceReverse_endAndBeginEqualNonSpace() {
    char a[10] = "abcdefghi";

    assert(&a[8] == findSpaceReverse(&a[8], &a[8]));
}

void test_findSpaceReverse_farRightRend() {
    char a[10] = "a cdefghi";

    assert(&a[1] == findSpaceReverse(&a[8], a));
}

void test_findSpaceReverse_classic() {
    char a[10] = "abcd fghi";

    assert(&a[4] == findSpaceReverse(&a[8], a));
}

void test_findSpaceReverse() {
    test_findSpaceReverse_notSpaceSymbol();
    test_findSpaceReverse_endAndBeginNonEqualSpaceLast();
    test_findSpaceReverse_endAndBeginEqualSpace();
    test_findSpaceReverse_endAndBeginEqualNonSpace();
    test_findSpaceReverse_farRightRend();
    test_findSpaceReverse_classic();

}

void test_strcmp_eqaulStr() {
    char a[6] = "Hello";
    char b[6] = "Hello";

    assert(strcmp_(a, b) == 0);
}

void test_strcmp_negativValue() {
    char a[6] = "Aello";
    char b[6] = "Bello";

    assert(strcmp_(a, b) < 0);
}

void test_strcmp_positivValue() {
    char a[6] = "Aello";
    char b[6] = "Bello";

    assert(strcmp_(b, a) > 0);
}

void test_strcmp_positivValueLast() {
    char a[6] = "HellA";
    char b[6] = "HellB";

    assert(strcmp_(b, a) > 0);
}

void test_strcmp() {
    test_strcmp_eqaulStr();
    test_strcmp_negativValue();
    test_strcmp_positivValue();
    test_strcmp_positivValueLast();
}

void test_copy_nullStrBigDiapozon() {
    char a[6] = "";
    char b[9];

    assert (copy(a, &a[4], b) == &b[4]);
}

void test_copy_nullStrNullDiapozon() {
    char a[6] = "";
    char b[9];

    assert (copy(a, a, b) == b);
}

void test_copy_fullStr() {
    char a[6] = "Hello";
    char b[9];

    *copy(a, &a[4], b) = '\0';

    ASSERT_STRING("Hell", b); // оу....
}

void test_copy() {
    test_copy_nullStrBigDiapozon();
    test_copy_nullStrNullDiapozon();
    test_copy_fullStr();
}

void test_getWordReverse_lastWord() {
    char s[] = "Lizi Lolita Margarita ";
    WordDescriptor word;
    assert(getWordReverse(&s[11], s, &word));
    assert(word.begin == &s[5] && word.end == &s[10]);
}

void test_getWordReverse_firstWord() {
    char s[] = "Liza Lolita Margarita";
    WordDescriptor word;
    assert(getWordReverse(&s[4], s, &word));
}

void test_getWordReverse_NonWord() {
    char s[10] = "";
    WordDescriptor word;
    assert(!getWordReverse(&s[4], s, &word));
}

void test_getWordReverse_fullWord() {
    char s[] = "Liza Lolita Margarita";
    WordDescriptor word;
    assert(getWordReverse(&s[4], s, &word));
}

void test_getWordReverse() {
    test_getWordReverse_lastWord();
    test_getWordReverse_firstWord();
    test_getWordReverse_NonWord();
    test_getWordReverse_fullWord();
}

void testB() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_getWordReverse();
}

/////////// taks ////////

void test_removeNonLetters_noSpace() {
    char s[] = "abcdefg";
    removeNonLetters(s);
    ASSERT_STRING("abcdefg", s);
}

void test_removeNonLetters_Space() {
    char s[] = " a b c d e f g ";
    removeNonLetters(s);
    ASSERT_STRING("abcdefg", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_noSpace();
    test_removeNonLetters_Space();
}


void test_removeAdjacentEqualLetters_noSpaceSymbol() {
    char s[] = "aaa111";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a1", s);
}

void test_removeAdjacentEqualLetters_SpaceSymbol() {
    char s[] = "a   a   a";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a a a", s);
}

void test_removeAdjacentEqualLetters_onlyEqualSymbol() {
    char s[] = "aaa";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a", s);
}

void test_removeAdjacentEqualLetters_onlyNonEqualSymbol() {
    char s[] = "abc";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("abc", s);
}

void test_removeAdjacentEqualLetters_complexStringt() {
    char s[] = "aaaaaa aaabbbbbbbbccccc c ";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("a abc c ", s);
}

void test_removeAdjacentEqualLetters_nullStr() {
    char s[] = "";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING("", s);
}

void test_removeAdjacentEqualLetters() {
    test_removeAdjacentEqualLetters_noSpaceSymbol();
    test_removeAdjacentEqualLetters_SpaceSymbol();
    test_removeAdjacentEqualLetters_onlyEqualSymbol();
    test_removeAdjacentEqualLetters_onlyNonEqualSymbol();
    test_removeAdjacentEqualLetters_complexStringt();
    test_removeAdjacentEqualLetters_nullStr();
}

void test_removeExtraSpaces_spaceLast() {
    char s[] = "aa    b       c       ";
    removeExtraSpaces(s);
    ASSERT_STRING("aa b c ", s);
}

void test_removeExtraSpaces_spaceFirstAndLast() {
    char s[] = "      a    b       c       ";
    removeExtraSpaces(s);
    ASSERT_STRING("a b c ", s);
}

void test_removeExtraSpaces_nullStr() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}


void test_removeExtraSpaces() {
    test_removeExtraSpaces_spaceLast();
    test_removeExtraSpaces_spaceFirstAndLast();
    test_removeExtraSpaces_nullStr();
}

void test_digitToStartString_nonDigit() {
    char s[] = "Hello";
    digitToStartString(s);
    ASSERT_STRING("Hello", s);
}

void test_digitToStartString_onlyDigit() {
    char s[] = "123";
    digitToStartString(s);
    ASSERT_STRING("321", s);
}

void test_digitToStartString_classicString() {
    char s[] = "Hi123 45Jo89";
    digitToStartString(s);
    ASSERT_STRING("321Hi 9854Jo", s);
}


void test_digitToStartString_complexWordString() {
    char s[] = "Hi123 45J80o89";
    digitToStartString(s);
    ASSERT_STRING("321Hi 980854Jo", s);
}

void test_digitToStartString_nullStr() {
    char s[] = "";
    digitToStartString(s);
    ASSERT_STRING("", s);
}

void test_digitToStartString() {
    test_digitToStartString_nonDigit();
    test_digitToStartString_onlyDigit();
    test_digitToStartString_classicString();
    test_digitToStartString_nullStr();
    test_digitToStartString_complexWordString();
}

void test_digitToEndSymbolToStartString_classic() {
    char s[] = "2345abc";
    digitToEndSymbolToStartString(s);
    ASSERT_STRING("abc2345", s);
}

void test_digitToEndSymbolToStartString_onlyDigit() {
    char s[] = "23 45";
    digitToEndSymbolToStartString(s);
    ASSERT_STRING("23 45", s);
}

void test_digitToEndSymbolToStartString_onlySymbol() {
    char s[] = "ba ku";
    digitToEndSymbolToStartString(s);
    ASSERT_STRING("ba ku", s);
}

void test_digitToEndSymbolToStartString_complexString() {
    char s[] = "4a1b23   56hu7l9  iko8  ";
    digitToEndSymbolToStartString(s);
    ASSERT_STRING("ab4123   hul5679  iko8  ", s);
}

void test_digitToEndSymbolToStartString_nullString() {
    char s[] = "";
    digitToEndSymbolToStartString(s);
    ASSERT_STRING("", s);
}

void test_digitToEndSymbolToStartString_veryDifferentWordInString() {
    char s[] = "4a1b23   56hu7l9  iko8  6565 1k1o1k1o12";
    digitToEndSymbolToStartString(s);
    ASSERT_STRING("ab4123   hul5679  iko8  6565 koko111112", s);
}

void test_digitToEndSymbolToStartString() {
    test_digitToEndSymbolToStartString_classic();
    test_digitToEndSymbolToStartString_onlyDigit();
    test_digitToEndSymbolToStartString_onlySymbol();
    test_digitToEndSymbolToStartString_complexString();
    test_digitToEndSymbolToStartString_nullString();
    test_digitToEndSymbolToStartString_veryDifferentWordInString();
}

void test_digitToEndReversSymbolToStartString_classic() {
    char s[] = "a1b2c3 a1b2c3";
    digitToEndReversSymbolToStartString(s);
    ASSERT_STRING("abc321 abc321", s);
}

void test_digitToEndReversSymbolToStartString_onlyDigit() {
    char s[] = "123 123";
    digitToEndReversSymbolToStartString(s);
    ASSERT_STRING("321 321", s);
}

void test_digitToEndReversSymbolToStartString_onlySymbol() {
    char s[] = "abc abc";
    digitToEndReversSymbolToStartString(s);
    ASSERT_STRING("abc abc", s);
}

void test_digitToEndReversSymbolToStartString_complexString() {
    char s[] = "2a56b1c a987b1c2";
    digitToEndReversSymbolToStartString(s);
    ASSERT_STRING("abc1652 abc21789", s);
}

void test_digitToEndReversSymbolToStartString_nullString() {
    char s[] = "";
    digitToEndReversSymbolToStartString(s);
    ASSERT_STRING("", s);
}

void test_digitToEndReversSymbolToStartString() {
    test_digitToEndReversSymbolToStartString_classic();
    test_digitToEndReversSymbolToStartString_onlyDigit();
    test_digitToEndReversSymbolToStartString_onlySymbol();
    test_digitToEndReversSymbolToStartString_complexString();
    test_digitToEndReversSymbolToStartString_nullString();
}

void test_digitToStartNonReversString_nonDigit() {
    char s[] = "Hello";
    digitToStartNonReversString(s);
    ASSERT_STRING("Hello", s);
}

void test_digitToStartNonReversString_onlyDigit() {
    char s[] = "123";
    digitToStartNonReversString(s);
    ASSERT_STRING("123", s);
}

void test_digitToStartNonReversString_classicString() {
    char s[] = "Hi123 45Jo89";
    digitToStartNonReversString(s);
    ASSERT_STRING("123Hi 4589Jo", s);
}


void test_digitToStartNonReversString_complexWordString() {
    char s[] = "Hi123 45J80o89";
    digitToStartNonReversString(s);
    ASSERT_STRING("123Hi 458089Jo", s);
}

void test_digitToStartNonReversString_nullStr() {
    char s[] = "";
    digitToStartNonReversString(s);
    ASSERT_STRING("", s);
}

void test_digitToStartNonReversString() {
    test_digitToStartNonReversString_nonDigit();
    test_digitToStartNonReversString_onlyDigit();
    test_digitToStartNonReversString_classicString();
    test_digitToStartNonReversString_nullStr();
    test_digitToStartNonReversString_complexWordString();
}

void test_reverseWordInString_oneWord() {
    char s[] = "    bibaAndBoba   ";
    reverseWordInString(s);
    ASSERT_STRING("    aboBdnAabib   ", s);
}

void test_reverseWordInString_bigString() {
    char s[] = "    bibaAndBoba   h1i2s3t4o5r6i";
    reverseWordInString(s);
    ASSERT_STRING("    aboBdnAabib   i6r5o4t3s2i1h", s);
}

void test_reverseWordInString_nullString() {
    char s[] = "";
    reverseWordInString(s);
    ASSERT_STRING("", s);
}

void test_reverseWordInString_onlySymbolOrOnlyDigit() {
    char s[] = "    bibaAndBoba   123456";
    reverseWordInString(s);
    ASSERT_STRING("    aboBdnAabib   654321", s);
}

void test_reverseWordInString() {
    test_reverseWordInString_oneWord();
    test_reverseWordInString_bigString();
    test_reverseWordInString_nullString();
    test_reverseWordInString_onlySymbolOrOnlyDigit();

}

#include "string/tasks/digitSpace.h"

void test_getDigitCountSpace_onlyDigit() {
    char s[] = "123";
    getDigitCountSpace(s);
    ASSERT_STRING("      ", s);

}

void test_getDigitCountSpace_onlySymbol() {
    char s[] = "abs";
    getDigitCountSpace(s);
    ASSERT_STRING("abs", s);
}

void test_getDigitCountSpace_nullStr() {
    char s[] = "";
    getDigitCountSpace(s);
    ASSERT_STRING("", s);
}

void test_getDigitCountSpace_complexStr() {
    char s[] = "ab1 2bs 3lkik5";
    getDigitCountSpace(s);
    ASSERT_STRING("ab    bs    lkik     ", s);
}

void test_getDigitCountSpace() {
    test_getDigitCountSpace_onlyDigit();
    test_getDigitCountSpace_onlySymbol();
    test_getDigitCountSpace_nullStr();
    test_getDigitCountSpace_complexStr();
}


// очень поздно сажусь делать 5 задание
// кажется меня ждёт -0.5 балла.
// но знаете 3.5 за экз это почти как 5.3 только наоборот


#include "string/tasks/replace.h"

void test_replace_wordsEqual() {
    char s[] = "The more I see the less I know";
    char w1[] = "know";
    char w2[] = "know";

    replace(s, w1, w2);

    ASSERT_STRING("The more I see the less I know", s);
}

void test_replace_w1BigW2Small() {
    char s[] = "The more I see the less I know";
    char w1[] = "know";
    char w2[] = "love";

    replace(s, w1, w2);

    ASSERT_STRING("The more I see the less I love", s);
}

void test_replace_w1SmallW2Big() {
    char s[] = "The more I see the less I know";
    char w1[] = "know";
    char w2[] = "love";

    replace(s, w1, w2);

    ASSERT_STRING("The more I see the less I love", s);
}

void test_replace_spaceApocalypse() {
    char s[] = "heroine \t       of           \n three-volume \t      novels";
    char w1[] = "three";
    char w2[] = "five";

    replace(s, w1, w2);

    ASSERT_STRING("heroine \t       of           \n five-volume \t      novels", s);
}

void test_replace_complexStr() {
    char s[] = "I've been acting stupid\n"
               "I didn't follow the speech\n"
               "I want to apologize\n"
               "But I dont know how";
    char w1[] = "I";
    char w2[] = "You";

    replace(s, w1, w2);

    ASSERT_STRING("You've been acting stupid\n"
                  "You didn't follow the speech\n"
                  "You want to apologize\n"
                  "But You dont know how", s);
}

// ничего интересного больше не будет

void test_replace_nullStr() {
    char s[] = "";
    char w1[] = "i'm";
    char w2[] = "sorry";

    replace(s, w1, w2);

    ASSERT_STRING("", s);
}

void test_replace_onlySpace() {
    char s[] = "                       ";
    char w1[] = "i'm";
    char w2[] = "sorry";

    replace(s, w1, w2);

    ASSERT_STRING("                       ", s);
}

void test_replace_onlyW1InStr() {
    char s[] = "frog frog frog frog frog";
    char w1[] = "frog";
    char w2[] = "green frog";

    replace(s, w1, w2);

    ASSERT_STRING("green frog green frog green frog green frog green frog", s);
}

void test_replace_onlyW2Str() {
    char s[] = "frog frog frog frog frog";
    char w2[] = "frog";
    char w1[] = "green frog";

    replace(s, w1, w2);

    ASSERT_STRING("frog frog frog frog frog", s);
}

void test_replace_w1InsideW2() {
    char s[] = "frog frog frog frog frog";
    char w1[] = "frog";
    char w2[] = "greenfrogs";

    replace(s, w1, w2);

    ASSERT_STRING("greenfrogs greenfrogs greenfrogs greenfrogs greenfrogs", s);
}

void test_replace_repeat() {
    char s[] = "the frog says qua-qua\n but I say \"I'm stupid\"";
    char w1[] = "frog";
    char w2[] = "dog";
    char w3[] = "qua-qua";
    char w4[] = "woof-woof";

    replace(s, w1, w2);
    replace(s, w3, w4);

    ASSERT_STRING("the dog says woof-woof\n but I say \"I'm stupid\"", s);
}


//12 тестов на функцию. Матушки боже.
// а нет 11. Я не умею считать. (и думать)
void test_replace() {
    test_replace_wordsEqual();
    test_replace_w1BigW2Small();
    test_replace_w1SmallW2Big();
    test_replace_spaceApocalypse();
    test_replace_complexStr();
    test_replace_nullStr();
    test_replace_onlySpace();
    test_replace_onlyW1InStr();
    test_replace_onlyW2Str();
    test_replace_w1InsideW2();
    test_replace_repeat();
}

void test_areWordsEqual_wordEqual() {
    char s[] = "I am couch potato";
    WordDescriptor word1;
    WordDescriptor word2;
    getWord(&s[5], &word1);
    getWord(&s[5], &word2);

    assert(areWordsEqual(word1, word2));
}

void test_areWordsEqual_wordNonEqual() {
    char s[] = "I am couch potato";
    WordDescriptor word1;
    WordDescriptor word2;
    getWord(&s[5], &word1);
    getWord(s, &word2);

    assert(!areWordsEqual(word1, word2));
}

void test_areWordsEqual() {
    test_areWordsEqual_wordEqual();
    test_areWordsEqual_wordNonEqual();
}

void test_getOrderTwoWord_order() {
    char s[] = "abcde abefg";
    WordDescriptor word1;
    WordDescriptor word2;
    getWord(s, &word1);
    getWord(&s[5], &word2);

    assert(getOrderTwoWord(word1, word2));

}

void test_getOrderTwoWord_nonOrder() {
    char s[] = "abcde abefg";
    WordDescriptor word1;
    WordDescriptor word2;
    getWord(s, &word1);
    getWord(&s[5], &word2);

    assert(!getOrderTwoWord(word2, word1));
}

void test_getOrderTwoWord_equal() {
    char s[] = "abcde abefg";
    WordDescriptor word1;
    WordDescriptor word2;
    getWord(s, &word1);
    getWord(s, &word2);

    assert(getOrderTwoWord(word1, word2));
}

void test_getOrderTwoWord() {
    test_getOrderTwoWord_order();
    test_getOrderTwoWord_nonOrder();
    test_getOrderTwoWord_equal();
}

#include "string/tasks/isOrderWord.h"

void test_isOrderWordInStr_nullStr() {
    char s[] = "";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_onlySpaceStr() {
    char s[] = "                     ";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_oneWord() {
    char s[] = "sad";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_twoWordOrder() {
    char s[] = "abcd adc";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_twoWordNonOrder() {
    char s[] = "abcd adcc";

    assert(!isOrderWordInStr(s));
}

void test_isOrderWordInStr_manySpaceInEndStr() {
    char s[] = "abcd adc         \n \n \t";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_spaceApocalypse() {
    char s[] = "  \n \n \t   abcd \n \n \t adc         \n \n \t";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_wordOrder() {
    char s[] = "abcd adc klmn mnop";

    assert(isOrderWordInStr(s));
}

void test_isOrderWordInStr_wordNonOrder() {
    char s[] = "abcd adc mnop  klmn";

    assert(!isOrderWordInStr(s));
}

void test_isOrderWordInStr_wordVeryDifferentLengths() {
    char s[] = "a abcdefg mn klmnqrstu";

    assert(!isOrderWordInStr(s));
}

//ещё 12 тестов. Елки-иголки....
void test_isOrderWordInStr() {
    test_areWordsEqual();
    test_getOrderTwoWord();
    test_isOrderWordInStr_nullStr();
    test_isOrderWordInStr_onlySpaceStr();
    test_isOrderWordInStr_oneWord();
    test_isOrderWordInStr_twoWordOrder();
    test_isOrderWordInStr_twoWordNonOrder();
    test_isOrderWordInStr_manySpaceInEndStr();
    test_isOrderWordInStr_spaceApocalypse();
    test_isOrderWordInStr_wordOrder();
    test_isOrderWordInStr_wordNonOrder();
    test_isOrderWordInStr_wordVeryDifferentLengths();
}


#include "string/tasks/ReverseWords.h"

void test_reverseWords_nullStr() {
    char s[] = "";
    reverseWords(s);

    ASSERT_STRING("", s);
}

void test_reverseWords_oneWord() {
    char s[] = "pain";
    reverseWords(s);

    ASSERT_STRING("pain", s);
}

void test_reverseWords_twoWord() {
    char s[] = "women's holiday";
    reverseWords(s);

    ASSERT_STRING("holiday women's", s);
}

void test_reverseWords_complexStr() {
    char s[] = "many names mean nothing to me. But I like your name.";
    reverseWords(s);
    // ради рофла расскажу если вводить name на русской раскладке получится тфьу

    ASSERT_STRING("name. your like I But me. to nothing mean names many", s);
}

void test_reverseWords_spaceApocalypse() {
    char s[] = "many   \n    \t     \t    names"
               "\n \n mean \t \t \n nothing \n to \n \t \n me.";
    reverseWords(s);

    ASSERT_STRING("me. to nothing mean names many", s);
}

void test_reverseWords() {
    test_reverseWords_nullStr();
    test_reverseWords_oneWord();
    test_reverseWords_twoWord();
    test_reverseWords_complexStr();
    test_reverseWords_spaceApocalypse();
}


#include "string/tasks/countPallendrom.h"

void test_getCountPallendrom_nullStr() {
    char s[] = "";
    int cntP = getCountPallendrom(s);

    assert(cntP == 0);
}

void test_getCountPallendrom_onlySpace() {
    char s[] = "                 ";
    int cntP = getCountPallendrom(s);

    assert(cntP == 0);
}

void test_getCountPallendrom_wordSeparatedSpace() {
    char s[] = "Madame Anna made Bob a dad at noon";

    int cntP = getCountPallendrom(s);

    assert(cntP == 0);
}

void test_getCountPallendrom_nonWordPallendrom() {
    char s[] = "abcffgcba abffgba  biba boba";
    int cntP = getCountPallendrom(s);

    assert(cntP == 0);
}

void test_getCountPallendrom_complexStr() {
    char s[] = "madam, anna, made, bob, a, dad, at, noon";
    int cntP = getCountPallendrom(s);

    assert(cntP == 6);
}

void test_getCountPallendrom_commaApocalypse() {
    char s[] = "madam,,,,,, , , , , , , ,,, , anna,, ,, , , , ,"
               "\n\n\n,,,,,,\n    made,"
               "\n,,,,, bob,,,,,, a,,,,, dad,, , , , , , , at,, , , , , noon";
    int cntP = getCountPallendrom(s);

    assert(cntP == 6);
}

void test_getCountPallendrom() {
    test_getCountPallendrom_nullStr();
    test_getCountPallendrom_onlySpace();
    test_getCountPallendrom_wordSeparatedSpace();
    test_getCountPallendrom_nonWordPallendrom();
    test_getCountPallendrom_complexStr();
    test_getCountPallendrom_commaApocalypse();
}

#include "string/tasks/getStringMerging.h"

void test_getStringMerging_nullStrFirst() {
    char s1[] = "";
    char s2[] = "string";
    int size = strlen_(s1) + strlen_(s2);
    char s[size];

    getStringMerging(s1, s2, s);

    ASSERT_STRING("string", s);
}

void test_getStringMerging_nullStrSecond() {
    char s1[] = "";
    char s2[] = "string";
    int size = strlen_(s1) + strlen_(s2);
    char s[size];

    getStringMerging(s2, s1, s);

    ASSERT_STRING("string", s);
}

void test_getStringMerging_nullTwoStr() {
    char s1[] = "";
    char s2[] = "";
    int size = strlen_(s1) + strlen_(s2);
    char s[size];

    getStringMerging(s1, s2, s);

    ASSERT_STRING("", s);
}

void test_getStringMerging_someStr() {
    char s2[] = "string";
    int size = strlen_(s2) + strlen_(s2);
    char s[size];

    getStringMerging(s2, s2, s);

    ASSERT_STRING("string string", s);
}

void test_getStringMerging_complexStr() {
    char s1[] = "I'm funny it hurts";
    char s2[] = "always and  never ";
    int size = strlen_(s1) + strlen_(s2);
    char s[size];

    getStringMerging(s1, s2, s);

    ASSERT_STRING("I'm always funny and it never hurts", s);
}

void test_getStringMerging_bigStrFirstAndSmallStrSecond() {
    char s1[] = "It's to work when you're dumb";
    char s2[] = "hard";
    int size = strlen_(s1) + strlen_(s2);
    char s[size];

    getStringMerging(s1, s2, s);

    ASSERT_STRING("It's hard to work when you're dumb", s);
}

void test_getStringMerging_bigStrSecondAndSmallStrFirst() {
    char s1[] = "It's to work when you're dumb";
    char s2[] = "hard";
    int size = strlen_(s1) + strlen_(s2);
    char s[size];

    getStringMerging(s2, s1, s);

    ASSERT_STRING("hard It's to work when you're dumb", s);
}

void test_getStringMerging() {
    test_getStringMerging_nullStrFirst();
    test_getStringMerging_nullStrSecond();
    test_getStringMerging_nullTwoStr();
    test_getStringMerging_someStr();
    test_getStringMerging_complexStr();
    test_getStringMerging_bigStrFirstAndSmallStrSecond();
    test_getStringMerging_bigStrSecondAndSmallStrFirst();
}

#include "string/tasks/isWordLettersSubsetStr.h"

void test_isWordLettersSubsetStr_nullStr(){
    char s[] = "";
    char w[] = "oh";
    WordDescriptor word;
    getWord(w, &word);

    assert(!isWordLettersSubsetStr(s, word));
}

void test_isWordLettersSubsetStr_subset(){
    char s[] = "Baby shark, doo doo doo doo doo doo."
               " Baby shark, doo doo doo doo doo doo."
               " Baby shark, doo doo doo doo doo doo."
               " Baby shark!";
    // жду сообщения в лс если кто-то пропел

    char w[] = "shark";
    WordDescriptor word;
    getWord(w, &word);

    assert(isWordLettersSubsetStr(s, word));
}

void test_isWordLettersSubsetStr_nonSubset(){
    char s[] = "Baby shark, doo doo doo doo doo doo."
               " Baby shark, doo doo doo doo doo doo."
               " Baby shark, doo doo doo doo doo doo."
               " Baby shark!";
    char w[] = "ohno";
    WordDescriptor word;
    getWord(w, &word);

    assert(!isWordLettersSubsetStr(s, word));
}
void test_isWordLettersSubsetStr_difficultSubset(){
    char s[] = "Baby shark, doo doo doo doo doo doo."
               " Baby shark, doo doo doo doo doo doo."
               " Baby shark, doo doo doo doo doo doo."
               " Baby shark!";
    char w[] = "ohbBaykr";
    WordDescriptor word;
    getWord(w, &word);

    assert(isWordLettersSubsetStr(s, word));
}

void test_isWordLettersSubsetStr(){
    test_isWordLettersSubsetStr_nullStr();
    test_isWordLettersSubsetStr_subset();
    test_isWordLettersSubsetStr_nonSubset();
    test_isWordLettersSubsetStr_difficultSubset();
}
#include "string/tasks/deleteEqualLastWord.h"

void test_deleteEqualLastWord_nullStr(){
    char s1[] = "";

    deleteEqualLastWord(&s1);

    ASSERT_STRING("", s1);
}

void test_deleteEqualLastWord_onlySpaceInStr(){
    char s1[] = "     ";

    deleteEqualLastWord(&s1);

    ASSERT_STRING("", s1);
}

void test_deleteEqualLastWord_complexStr(){
    char s1[] = " aaa bbb nn aaa nn aaa";

    deleteEqualLastWord(s1);

    ASSERT_STRING("bbb nn nn ", s1);
}

void test_deleteEqualLastWord_oneWord(){
    char s1[] = " based";

    deleteEqualLastWord(s1);

    ASSERT_STRING("", s1);
}

void test_deleteEqualLastWord_lonelyLastWord(){
    char s1[] = "never gonna give you up";

    deleteEqualLastWord(s1);

    ASSERT_STRING("never gonna give you ", s1);
}
void test_deleteEqualLastWord_onlyLastWordInComplexStr(){
    char s1[] = "criminal criminal criminal criminal";

    deleteEqualLastWord(s1);

    ASSERT_STRING("", s1);
}

void test_deleteEqualLastWord(){
    test_deleteEqualLastWord_nullStr();
    test_deleteEqualLastWord_onlySpaceInStr();
    test_deleteEqualLastWord_complexStr();
    test_deleteEqualLastWord_oneWord();
    test_deleteEqualLastWord_lonelyLastWord();
    test_deleteEqualLastWord_onlyLastWordInComplexStr();
}


#include "string/tasks/deleteWordPallendrom.h"

void test_deleteWordPallendrom_nullStr(){
    char s1[] = "";

    deleteWordPallendrom(s1);

    ASSERT_STRING("", s1);
}

void test_deleteWordPallendrom_onlySpaceStr(){
    char s1[] = "    ";

    deleteWordPallendrom(s1);

    ASSERT_STRING("", s1);
}

void test_deleteWordPallendrom_complexStr(){
    char s1[] = "anna verSUS train bob verSUS butter jesSUS verSUS everyone dad verSUS me";

    deleteWordPallendrom(s1);

    ASSERT_STRING("verSUS train verSUS butter jesSUS verSUS everyone verSUS me ", s1);
}

void test_deleteWordPallendrom_noPall(){
    char s1[] = "somebody ones told me the world is gonna roll me";

    deleteWordPallendrom(s1);

    ASSERT_STRING("somebody ones told me the world is gonna roll me ", s1);
}

void test_deleteWordPallendrom_onlyOneWord(){
    char s1[] = "anna";

    deleteWordPallendrom(s1);

    ASSERT_STRING("", s1);
}
void test_deleteWordPallendrom_onlyOneWordNonPall(){
    char s1[] = "train";

    deleteWordPallendrom(s1);

    ASSERT_STRING("train ", s1);
}
void test_deleteWordPallendrom_allWordsPall(){
    char s1[] = "anna mom dad bob anna mom dad dad";

    deleteWordPallendrom(s1);

    ASSERT_STRING("", s1);
}

void test_deleteWordPallendrom(){
    test_deleteWordPallendrom_nullStr();
    test_deleteWordPallendrom_onlySpaceStr();
    test_deleteWordPallendrom_complexStr();
    test_deleteWordPallendrom_noPall();
    test_deleteWordPallendrom_onlyOneWord();
    test_deleteWordPallendrom_onlyOneWordNonPall();
    test_deleteWordPallendrom_allWordsPall();

}

#include "string/tasks/deleteSequenceInWord.h"

void test_deleteSequenceInWord_nullStr(){
    char s1[] = "";
    char s2[] = "nn";

    deleteSequenceInWord(s1, s2);

    ASSERT_STRING("", s1);
}
void test_deleteSequenceInWord_onlySpace(){
    char s1[] = "          ";
    char s2[] = "nn";

    deleteSequenceInWord(s1, s2);

    ASSERT_STRING("", s1);
}
void test_deleteSequenceInWord_complex(){
    char s1[] = "anna verSUS train bob verSUS butter jesSUS verSUS everyone dad verSUS me";
    char s2[] = "SUS";

    deleteSequenceInWord(s1, s2);

    ASSERT_STRING("anna train bob butter everyone dad me ", s1);
}
void test_deleteSequenceInWord_noSeqWords(){
    char s1[] = "red and Blue";
    char s2[] = "nn";

    deleteSequenceInWord(s1, s2);

    ASSERT_STRING("red and Blue ", s1);
}
void test_deleteSequenceInWord_nullSeq(){
    char s1[] = "red and Blue";
    char s2[] = "";

    deleteSequenceInWord(s1, s2);

    ASSERT_STRING("red and Blue ", s1);
}
void test_deleteSequenceInWord_allWordsSeq(){
    char s1[] = "aaa aaaaa aaa aaaaa";
    char s2[] = "a";

    deleteSequenceInWord(s1, s2);

    ASSERT_STRING("", s1);
}

void test_deleteSequenceInWord(){
    test_deleteSequenceInWord_nullStr();
    test_deleteSequenceInWord_onlySpace();
    test_deleteSequenceInWord_complex();
    test_deleteSequenceInWord_noSeqWords();
    test_deleteSequenceInWord_nullSeq();
    test_deleteSequenceInWord_allWordsSeq();
}

//
//void test_deleteRepeatingCharinWord_nullStr(){
//    char s1[] = "";
//
//    deleteRepeatingCharinWord(&s1);
//
//    ASSERT_STRING("", s1);
//}
//
//void test_deleteRepeatingCharinWord_equalWord(){
//    char s1[] = "Rus  Rus Rus Rus   Rus Rus  Rus ";
//
//    deleteRepeatingCharinWord(&s1);
//
//    ASSERT_STRING("Rus Rus Rus Rus Rus Rus Rus ", s1);
//}
//
//void test_deleteRepeatingCharinWord_repeatChar(){
//    char s1[] = "Russ  Russ Russ Russ   Russ Russ  Russ ";
//
//    deleteRepeatingCharinWord(&s1);
//
//    ASSERT_STRING("", s1);
//}
//void test_deleteRepeatingCharinWord_onlySpace(){
//    char s1[] = "     ";
//
//    deleteRepeatingCharinWord(&s1);
//
//    ASSERT_STRING("     ", s1);
//}
//
//void test_deleteRepeatingCharinWord(){
//    test_deleteRepeatingCharinWord_nullStr();
//    test_deleteRepeatingCharinWord_equalWord();
//    test_deleteRepeatingCharinWord_repeatChar();
//    test_deleteRepeatingCharinWord_onlySpace();
//}

void testTask() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitToStartString();
    test_digitToEndSymbolToStartString();
    test_digitToEndReversSymbolToStartString();
    test_digitToStartNonReversString();
    test_reverseWordInString();
    test_getDigitCountSpace();
    test_isOrderWordInStr();
    test_reverseWords();
    test_getCountPallendrom();
    test_getStringMerging();
    test_isWordLettersSubsetStr();
    test_deleteEqualLastWord();
    test_deleteWordPallendrom();
   test_deleteSequenceInWord();
//    test_deleteRepeatingCharinWord();
    //   test_replace();
}


int main() {
    testB();
    testTask();

    return 0;
}