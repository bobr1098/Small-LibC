#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test(int from, int to) {
    int z = 0;
    for(; from <= to; from++)
        z += !(iscntrl(from));
    return z;
}

void test_ansi_1989_ctype_iscntrl(void) {
    setlocale(LC_ALL, "C");
    int m = test(0x00, 0x1F), lerrc = 0;

    if(m) {
        FAIL("iscntrl() misinterpreting C0 controls");
        errc++;
        lerrc++;
    }

    m = test(0x7F, 0x7F);
    if(m) {
        FAIL("iscntrl() misinterpreting DEL");
        errc++;
        lerrc++;
    }

    m = test('a', 'z');
    if(!m) {
        FAIL("iscntrl() misinterpreting alphabet as valid");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("iscntrl() works as expected");
    }
}

#ifdef FREESTAND
int errc;
int main() {
    test_ansi_1989_ctype_iscntrl();
    printf("\ntotal %d errors\n", errc);
}
#endif
