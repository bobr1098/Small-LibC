#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(isprint(from));
    return z;
}

void test_ansi_1989_ctype_isprint(void) {
    setlocale(LC_ALL, "C");
    int m = test(' ', '~'), lerrc = 0;

    if(m) {
        FAIL("isprint() misinterpreting printable characters");
        errc++;
        lerrc++;
    }

    m = test(0x00, 0x1F);
    if(!m) {
        FAIL("isprint() misinterpreting controls as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("isprint() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_isprint();
    printf("\ntotal %d errors\n", errc);
}
#endif
