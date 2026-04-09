#include <ctype.h>

int isupper(int c) {
    return (unsigned int)c - 'A' < 26;
}
