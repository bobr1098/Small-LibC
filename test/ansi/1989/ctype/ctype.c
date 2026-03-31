#include "../../../test.h"
#include <stdio.h>

void test_ansi_1989_ctype_isalnum(void);
void test_ansi_1989_ctype_isalpha(void);
void test_ansi_1989_ctype_iscntrl(void);
void test_ansi_1989_ctype_isdigit(void);
void test_ansi_1989_ctype_isgraph(void);
void test_ansi_1989_ctype_islower(void);
void test_ansi_1989_ctype_isprint(void);
void test_ansi_1989_ctype_ispunct(void);
void test_ansi_1989_ctype_isspace(void);
void test_ansi_1989_ctype_isupper(void);
void test_ansi_1989_ctype_isxdigit(void);
void test_ansi_1989_ctype_tolower(void);
void test_ansi_1989_ctype_toupper(void);

void test_ansi_1989_ctype(void) {
    test_ansi_1989_ctype_isalnum();
    test_ansi_1989_ctype_isalpha();
    test_ansi_1989_ctype_iscntrl();
    test_ansi_1989_ctype_isdigit();
    test_ansi_1989_ctype_isgraph();
    test_ansi_1989_ctype_islower();
    test_ansi_1989_ctype_isprint();
    test_ansi_1989_ctype_ispunct();
    test_ansi_1989_ctype_isspace();
    test_ansi_1989_ctype_isupper();
    test_ansi_1989_ctype_isxdigit();
    test_ansi_1989_ctype_tolower();
    test_ansi_1989_ctype_toupper();
}

#ifdef FREESTAND_CTYPE

int errc;

int main() {
    test_ansi_1989_ctype();
    printf("\ntotal %d errors\n", errc);
}

#endif /* FREESTAND_CTYPE */
