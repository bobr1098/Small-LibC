#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isgraph(from));
    return z;
}

void test_ansi_1989_ctype_isgraph(void) {
    setlocale(LC_ALL, "C");
    int m = test('!', '~'), lerrc = 0;

    if(m) {
        FAIL("isgraph() misinterpreting graphical characters");
        errc++;
        lerrc++;
    }

    m = test(' ', ' ');
    if(!m) {
        FAIL("isgraph() misinterpreting space as valid");
        errc++;
        lerrc++;
    }

    m = test(0x00, 0x1F);
    if(!m) {
        FAIL("isgraph() misinterpreting controls as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isgraph() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isgraph();
    printf("\ntotal %d errors\n", errc);
}
#endif
