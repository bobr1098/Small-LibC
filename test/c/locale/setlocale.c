#include <locale.h>
#include <stdio.h>
#include <string.h>

#define RED(txt) "\033[0;31m" txt "\033[0m"
#define GREEN(txt) "\033[0;32m" txt "\033[0m"

void setlocale_test() {
    if(strcmp(setlocale(LC_ALL, "C"), "C") != 0 || strcmp(setlocale(LC_ALL, NULL), "C") != 0)
        printf(RED("[FAIL]") " setlocale sets and queries \"C\" locale correctly\n");
    else
        printf(GREEN("[PASS]") " setlocale sets and queries \"C\" locale correctly\n");
}
