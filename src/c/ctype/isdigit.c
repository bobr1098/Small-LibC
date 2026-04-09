#include <ctype.h>

int isdigit(int c) {
    return (unsigned int)c - '0' < 10;
}
