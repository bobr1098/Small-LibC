#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isalpha(from));
    return z;
}

void test_ansi_1989_ctype_isalpha(void) {
    setlocale(LC_ALL, "C");
    int m = test('a', 'z'), lerrc = 0;

    if(m) {
        FAIL("isalpha() misinterpreting lowercase");
        errc++;
        lerrc++;
    }

    m = test('A', 'Z');
    if(m) {
        FAIL("isalpha() misinterpreting uppercase");
        errc++;
        lerrc++;
    }

    m = test('0', '9');
    if(!m) {
        FAIL("isalpha() misinterpreting numerals as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isalpha() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isalpha();
    printf("\ntotal %d errors\n", errc);
}
#endif
