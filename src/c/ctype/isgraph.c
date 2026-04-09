#include <ctype.h>

int isgraph(int c) {
    return (unsigned int)c - '!' < 94;
}
