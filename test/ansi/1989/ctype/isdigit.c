#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isdigit(from));
    return z;
}

void test_ansi_1989_ctype_isdigit(void) {
    setlocale(LC_ALL, "C");
    int m = test('0', '9'), lerrc = 0;

    if(m) {
        FAIL("isdigit() misinterpreting numerals");
        errc++;
        lerrc++;
    }

    m = test('a', 'z');
    if(!m) {
        FAIL("isdigit() misinterpreting lowercase as valid");
        errc++;
        lerrc++;
    }

    m = test('A', 'Z');
    if(!m) {
        FAIL("isdigit() misinterpreting uppercase as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isdigit() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isdigit();
    printf("\ntotal %d errors\n", errc);
}
#endif
