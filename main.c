#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include <memory.h>
#include <math.h>
#include "libs/data_structures/5dquestions/questions.h"
//#include <string.h>
#include "string/string_.h"


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

    assert(strcmp(a, b) == 0);
}

void test_strcmp_negativValue() {
    char a[6] = "Aello";
    char b[6] = "Bello";

    assert(strcmp(a, b) < 0);
}

void test_strcmp_positivValue(){
    char a[6] = "Aello";
    char b[6] = "Bello";

    assert(strcmp(b, a) > 0);
}

void test_strcmp_positivValueLast(){
    char a[6] = "HellA";
    char b[6] = "HellB";

    assert(strcmp(b, a) > 0);
}

void test_strcmp() {
    test_strcmp_eqaulStr();
    test_strcmp_negativValue();
    test_strcmp_positivValue();
    test_strcmp_positivValueLast();
}

void test_copy_nullStrBigDiapozon(){
    char a[6] = "";
    char b[9];

    assert (copy(a, &a[4], b) == &b[4]);
}

void test_copy_nullStrNullDiapozon(){
    char a[6] = "";
    char b[9];

    assert (copy(a, a, b) == b);
}

void test_copy_fullStr(){
    char a[6] = "Hello";
    char b[9];

    assert (copy(a, &a[4], b) == &b[4]);
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

int main() {
    testB();

    return 0;
}