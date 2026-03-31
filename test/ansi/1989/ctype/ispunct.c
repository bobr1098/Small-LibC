#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(ispunct(from));
    return z;
}

void test_ansi_1989_ctype_ispunct(void) {
    setlocale(LC_ALL, "C");
    int m = test('!', '/'), lerrc = 0;

    if(m) {
        FAIL("ispunct() misinterpreting punctuation");
        errc++;
        lerrc++;
    }

    m = test(':', '@');
    if(m) {
        FAIL("ispunct() misinterpreting more punctuation");
        errc++;
        lerrc++;
    }

    m = test('a', 'z');
    if(!m) {
        FAIL("ispunct() misinterpreting alphabet as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("ispunct() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_ispunct();
    printf("\ntotal %d errors\n", errc);
}
#endif
