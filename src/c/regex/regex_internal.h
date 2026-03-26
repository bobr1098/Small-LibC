#ifndef REGEX_INTERNAL_H
#define REGEX_INTERNAL_H

#include <regex.h>
#include <stddef.h>

typedef enum {
    AST_EMPTY,
    AST_CHAR,
    AST_ANY,
    AST_BOL,
    AST_EOL,
    AST_BRACKET,
    AST_BACKREF,
    AST_CONCAT,
    AST_ALT,
    AST_STAR,
    AST_GROUP,
    AST_GROUP_END
} AstOp;

typedef struct {
    AstOp op;
    int v1;
    int v2;
    int left;
    int right;
} AstNode;

typedef struct {
    AstNode *nodes;
    int root;
    char *pat;
    size_t prog_len;
} CompData;

#endif /* !REGEX_INTERNAL_H */
