#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include <memory.h>
#include <math.h>
#include "libs/data_structures/5dquestions/questions.h"
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

void testB() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
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

void test_reverseWordInString_oneWord(){
    char s[] ="    bibaAndBoba   ";
    reverseWordInString(s);
    ASSERT_STRING("    aboBdnAabib   ", s);
}

void test_reverseWordInString_bigString(){
    char s[] ="    bibaAndBoba   h1i2s3t4o5r6i";
    reverseWordInString(s);
    ASSERT_STRING("    aboBdnAabib   i6r5o4t3s2i1h", s);
}

void test_reverseWordInString_nullString(){
    char s[] ="";
    reverseWordInString(s);
    ASSERT_STRING("", s);
}

void test_reverseWordInString_onlySymbolOrOnlyDigit(){
    char s[] ="    bibaAndBoba   123456";
    reverseWordInString(s);
    ASSERT_STRING("    aboBdnAabib   654321", s);
}

void test_reverseWordInString() {
    test_reverseWordInString_oneWord();
    test_reverseWordInString_bigString();
    test_reverseWordInString_nullString();
    test_reverseWordInString_onlySymbolOrOnlyDigit();

}


void testTask() {
    test_removeNonLetters();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitToStartString();
    test_digitToEndSymbolToStartString();
    test_digitToEndReversSymbolToStartString();
    test_digitToStartNonReversString();
    test_reverseWordInString();
}


int main() {
    testB();
    testTask();

    return 0;
}