#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test_conversion(int from, int to) {
    int z = 0;
    for(int i = from; i <= to; i++) {
        z += (toupper(i) != (i - 'a' + 'A'));
    }
    return z;
}

static int inline test_no_change(int from, int to) {
    int z = 0;
    for(; from <= to; from++) {
        z += (toupper(from) != from);
    }
    return z;
}

void test_ansi_1989_ctype_toupper(void) {
    setlocale(LC_ALL, "C");
    int m = 0, lerrc = 0;

    m = test_conversion('a', 'z');
    if(m) {
        FAIL("toupper() fails to convert lowercase to uppercase");
        errc++;
        lerrc++;
    }

    m = test_no_change('A', 'Z');
    if(m) {
        FAIL("toupper() incorrectly modifies uppercase characters");
        errc++;
        lerrc++;
    }

    m = test_no_change('0', '9');
    if(m) {
        FAIL("toupper() incorrectly modifies numerals");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("toupper() works as expected");
    }
}

#ifdef FREESTAND

int errc;

int main() {
    test_ansi_1989_ctype_toupper();
    printf("\ntotal %d errors\n", errc);
}

#endif
