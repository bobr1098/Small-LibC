#include <ctype.h>

int islower(int c) {
    return (unsigned int)c - 'a' < 26;
}
