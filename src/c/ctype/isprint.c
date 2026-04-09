#include <ctype.h>

int isprint(int c) {
    return (unsigned int)c - ' ' < 95;
}
