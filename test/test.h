#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED   "\033[0;31m"
#define COLOR_RESET "\033[0m"

#define PASS(fmt, ...) do { \
    if (isatty(STDOUT_FILENO)) { \
        printf(COLOR_GREEN "[PASS]" COLOR_RESET " " fmt "\n", ##__VA_ARGS__); \
    } else { \
        printf("[PASS] " fmt "\n", ##__VA_ARGS__); \
    } \
} while (0)

#define FAIL(fmt, ...) do { \
    if (isatty(STDOUT_FILENO)) { \
        printf(COLOR_RED "[FAIL]" COLOR_RESET " " fmt "\n", ##__VA_ARGS__); \
    } else { \
        printf("[FAIL] " fmt "\n", ##__VA_ARGS__); \
    } \
} while (0)

extern int errc;
