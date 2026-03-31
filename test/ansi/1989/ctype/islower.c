#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(islower(from));
    return z;
}

void test_ansi_1989_ctype_islower(void) {
    setlocale(LC_ALL, "C");
    int m = test('a', 'z'), lerrc = 0;

    if(m) {
        FAIL("islower() misinterpreting lowercase");
        errc++;
        lerrc++;
    }

    m = test('A', 'Z');
    if(!m) {
        FAIL("islower() misinterpreting uppercase as valid");
        errc++;
        lerrc++;
    }

    m = test('0', '9');
    if(!m) {
        FAIL("islower() misinterpreting numerals as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("islower() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_islower();
    printf("\ntotal %d errors\n", errc);
}
#endif
