#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isupper(from));
    return z;
}

void test_ansi_1989_ctype_isupper(void) {
    setlocale(LC_ALL, "C");
    int m = test('A', 'Z'), lerrc = 0;

    if(m) {
        FAIL("isupper() misinterpreting uppercase");
        errc++;
        lerrc++;
    }

    m = test('a', 'z');
    if(!m) {
        FAIL("isupper() misinterpreting lowercase as valid");
        errc++;
        lerrc++;
    }

    m = test('0', '9');
    if(!m) {
        FAIL("isupper() misinterpreting numerals as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isupper() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isupper();
    printf("\ntotal %d errors\n", errc);
}
#endif
