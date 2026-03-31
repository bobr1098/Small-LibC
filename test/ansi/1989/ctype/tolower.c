
#include "../../../test.h"
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>

static int inline test_conversion(int from, int to) {
    int z = 0;
    for(int i = from; i <= to; i++) {
        z += (tolower(i) != (i - 'A' + 'a'));
    }
    return z;
}

static int inline test_no_change(int from, int to) {
    int z = 0;
    for(; from <= to; from++) {
        z += (tolower(from) != from);
    }
    return z;
}

void test_ansi_1989_ctype_tolower(void) {
    setlocale(LC_ALL, "C");
    int m = 0, lerrc = 0;

    m = test_conversion('A', 'Z');
    if(m) {
        FAIL("tolower() fails to convert uppercase to lowercase");
        errc++;
        lerrc++;
    }

    m = test_no_change('a', 'z');
    if(m) {
        FAIL("tolower() incorrectly modifies lowercase characters");
        errc++;
        lerrc++;
    }

    m = test_no_change('0', '9');
    if(m) {
        FAIL("tolower() incorrectly modifies numerals");
        errc++;
        lerrc++;
    }

    if(!lerrc) {
        PASS("tolower() works as expected");
    }
}

#ifdef FREESTAND

int errc;

int main() {
    test_ansi_1989_ctype_tolower();
    printf("\ntotal %d errors\n", errc);
}

#endif
