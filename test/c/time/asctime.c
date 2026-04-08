// asctime_test.c - Unit tests for asctime() function
// Tests verify: output format, padding, boundary values, static buffer behavior

#include <stdio.h>
#include <string.h>
#include <time.h>

#define RED(txt) "\033[0;31m" txt "\033[0m"
#define GREEN(txt) "\033[0;32m" txt "\033[0m"

// Helper: compare asctime() output with expected string
static int check_asctime(const struct tm *tm, const char *expected) {
    char *result = asctime(tm);
    return (result != NULL) && (strcmp(result, expected) == 0);
}

void asctime_test(void) {
    struct tm test_tm;
    char *result;

    // Test 1: Basic known date (Sun Sep 16 01:03:52 1973)
    memset(&test_tm, 0, sizeof(test_tm));  // Initialize all fields to zero
    test_tm.tm_sec = 52;
    test_tm.tm_min = 3;
    test_tm.tm_hour = 1;
    test_tm.tm_mday = 16;
    test_tm.tm_mon = 8;      // September (0-11)
    test_tm.tm_year = 73;    // 1973
    test_tm.tm_wday = 0;     // Sunday
    
    if (check_asctime(&test_tm, "Sun Sep 16 01:03:52 1973\n")){
        printf(GREEN("[PASS]") " asctime formats basic date correctly\n");
    }else{
        printf(RED("[FAIL]") " asctime formats basic date correctly\n");
    }

    // Test 2: Single-digit day padding with space
    test_tm.tm_mday = 5;
    if (check_asctime(&test_tm, "Sun Sep  5 01:03:52 1973\n")){
        printf(GREEN("[PASS]") " asctime pads single-digit day with space\n");
    }else{
        printf(RED("[FAIL]") " asctime pads single-digit day with space\n");
    }

    // Test 3: Double-digit day without padding
    test_tm.tm_mday = 25;
    if (check_asctime(&test_tm, "Sun Sep 25 01:03:52 1973\n")){
        printf(GREEN("[PASS]") " asctime formats double-digit day without padding\n");
    }else{
        printf(RED("[FAIL]") " asctime formats double-digit day without padding\n");
    }

    // Test 4: Zero time values (00:00:00)
    test_tm.tm_hour = 0;
    test_tm.tm_min = 0;
    test_tm.tm_sec = 0;
    test_tm.tm_mday = 1;
    if (check_asctime(&test_tm, "Sun Sep  1 00:00:00 1973\n")){
        printf(GREEN("[PASS]") " asctime handles zero time values\n");
    }else{
        printf(RED("[FAIL]") " asctime handles zero time values\n");
    }

    // Test 5: Maximum time values (23:59:59)
    test_tm.tm_hour = 23;
    test_tm.tm_min = 59;
    test_tm.tm_sec = 59;
    if (check_asctime(&test_tm, "Sun Sep  1 23:59:59 1973\n")){
        printf(GREEN("[PASS]") " asctime handles max time values\n");
    }else{
        printf(RED("[FAIL]") " asctime handles max time values\n");
    }

    // Test 6: Correct weekday abbreviation (Saturday)
    test_tm.tm_wday = 6;     // Saturday
    test_tm.tm_mon = 0;      // January
    test_tm.tm_mday = 15;
    if (check_asctime(&test_tm, "Sat Jan 15 23:59:59 1973\n")){
        printf(GREEN("[PASS]") " asctime uses correct weekday abbreviation\n");
    }else{
        printf(RED("[FAIL]") " asctime uses correct weekday abbreviation\n");
    }
    // Test 7: Correct month abbreviation (December)
    test_tm.tm_mon = 11;     // December
    if (check_asctime(&test_tm, "Sat Dec 15 23:59:59 1973\n")){
        printf(GREEN("[PASS]") " asctime uses correct month abbreviation\n");
    }else{
        printf(RED("[FAIL]") " asctime uses correct month abbreviation\n");
    }
    // Test 8: Year >= 2000 (tm_year = 123 -> 2023)
    test_tm.tm_year = 123;
    test_tm.tm_mon = 0;
    test_tm.tm_mday = 1;
    test_tm.tm_wday = 0;
    if (check_asctime(&test_tm, "Sun Jan  1 23:59:59 2023\n")){
        printf(GREEN("[PASS]") " asctime handles year >= 2000\n");
    }else{
        printf(RED("[FAIL]") " asctime handles year >= 2000\n");
    }
    // Test 9: Return value points to static buffer (same address on repeated calls)
    result = asctime(&test_tm);
    if (result != NULL && result == asctime(&test_tm)){
        printf(GREEN("[PASS]") " asctime returns pointer to static buffer\n");
    }else{
        printf(RED("[FAIL]") " asctime returns pointer to static buffer\n");
    }
    // Test 10: Result length is 25 chars + newline + null terminator
    // Format: "Www Mmm dd hh:mm:ss yyyy\n\0" = 24 visible + \n + \0
    if (result != NULL && strlen(result) == 25){
        printf(GREEN("[PASS]") " asctime result length is 25 chars (+ \\n + \\0)\n");
    }else{
        printf(RED("[FAIL]") " asctime result length is 25 chars (+ \\n + \\0)\n");
    }
    // Test 11: String terminates with newline followed by null byte
    if (result != NULL && result[24] == '\n' && result[25] == '\0'){
        printf(GREEN("[PASS]") " asctime terminates with \\n\\0\n");
    }else{
        printf(RED("[FAIL]") " asctime terminates with \\n\\0\n");
    }
    // Test 12: Static buffer is overwritten on subsequent calls
    test_tm.tm_year = 70;  // 1970
    char *first = asctime(&test_tm);
    test_tm.tm_year = 80;  // 1980
    char *second = asctime(&test_tm);
    if (first == second && strcmp(first, "Sun Jan  1 23:59:59 1980\n") == 0){
        printf(GREEN("[PASS]") " asctime static buffer is overwritten on next call\n");
    }else{
        printf(RED("[FAIL]") " asctime static buffer is overwritten on next call\n");
    }
    // Note: asctime(NULL) behavior is undefined by C standard.
    // This implementation may crash or return garbage; not tested here.
}