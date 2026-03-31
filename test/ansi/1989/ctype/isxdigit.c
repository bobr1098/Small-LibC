#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isxdigit(from));
    return z;
}

void test_ansi_1989_ctype_isxdigit(void) {
    setlocale(LC_ALL, "C");
    int m = test('0', '9'), lerrc = 0;

    if(m) {
        FAIL("isxdigit() misinterpreting numerals");
        errc++;
        lerrc++;
    }

    m = test('a', 'f');
    if(m) {
        FAIL("isxdigit() misinterpreting lowercase hex");
        errc++;
        lerrc++;
    }

    m = test('A', 'F');
    if(m) {
        FAIL("isxdigit() misinterpreting uppercase hex");
        errc++;
        lerrc++;
    }

    m = test('g', 'z');
    if(!m) {
        FAIL("isxdigit() misinterpreting non-hex alphabet as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isxdigit() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isxdigit();
    printf("\ntotal %d errors\n", errc);
}
#endif
