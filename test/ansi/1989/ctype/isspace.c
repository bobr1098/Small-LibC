#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isspace(from));
    return z;
}

void test_ansi_1989_ctype_isspace(void) {
    setlocale(LC_ALL, "C");
    int m = test('\t', '\r'), lerrc = 0;

    if(m) {
        FAIL("isspace() misinterpreting whitespace controls");
        errc++;
        lerrc++;
    }

    m = test(' ', ' ');
    if(m) {
        FAIL("isspace() misinterpreting space");
        errc++;
        lerrc++;
    }

    m = test('a', 'z');
    if(!m) {
        FAIL("isspace() misinterpreting alphabet as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isspace() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isspace();
    printf("\ntotal %d errors\n", errc);
}
#endif
