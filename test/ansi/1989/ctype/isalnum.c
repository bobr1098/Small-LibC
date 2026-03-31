#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isalnum(from));
    return z;
}

void test_ansi_1989_ctype_isalnum(void) {
    setlocale(LC_ALL, "C");
    int m = test('0', '9'), lerrc = 0;

    if(m) {
        FAIL("isalnum() misinterpreting numerals");
        errc++;
        lerrc++;
    }

    m = test('a', 'z');
    if(m) {
        FAIL("isalnum() misinterpreting lowercase");
        errc++;
        lerrc++;
    }

    m = test('A', 'Z');
    if(m) {
        FAIL("isalnum() misinterpreting uppercase");
        errc++;
        lerrc++;
    }

    m = test(' ', '*');
    if(!m) {
        FAIL("isalnum() misinterpreting non-alphabet and non-numerals as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isalnum() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isalnum();
    printf("\ntotal %d errors\n", errc);
}
#endif
