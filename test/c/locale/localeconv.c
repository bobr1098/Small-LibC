#include <locale.h>
#include <stdio.h>
#include <string.h>

#define RED(txt) "\033[0;31m" txt "\033[0m"
#define GREEN(txt) "\033[0;32m" txt "\033[0m"

void localeconv_test() {
    struct lconv *lconv = localeconv();

    if(lconv == NULL)
        printf(RED("[FAIL]") " localeconv returns a non-NULL pointer\n");
    else
        printf(GREEN("[PASS]") " localeconv returns a non-NULL pointer\n");

    if(!lconv || strcmp(lconv->decimal_point, ".") != 0 || strcmp(lconv->thousands_sep, "") != 0)
        printf(RED("[FAIL]") " localeconv returns correct default separators\n");
    else
        printf(GREEN("[PASS]") " localeconv returns correct default separators\n");

    if(!lconv || (strcmp(lconv->grouping, "") != 0 && strcmp(lconv->grouping, "\x7f") != 0))
        printf(RED("[FAIL]") " localeconv returns correct default grouping\n");
    else
        printf(GREEN("[PASS]") " localeconv returns correct default grouping\n");
}
