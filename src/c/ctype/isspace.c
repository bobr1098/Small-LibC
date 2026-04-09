#include <ctype.h>

int isspace(int c) {
    return c == ' ' || (unsigned int)c - '\t' < 5;
}
