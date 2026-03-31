#include "../../../test.h"
#include <assert.h>
#include <sys/wait.h>
#include <unistd.h>

int static inline test(void (*func)()) {
    pid_t pid = fork();
    if(pid < 0) {
        perror("fork() failed");
        exit(-1);
    }
    if(!pid) {
        close(STDERR_FILENO);
        func();
        exit(0);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if(WIFSIGNALED(status) && WTERMSIG(status) == SIGABRT)
            return 1;
        else
            return 2;
    }
}

static inline void assert_success(void) {
    assert(1);
}

static inline void assert_fail(void) {
    assert(0);
}

void test_ansi_1989_assert_assert(void) {
    int lerrc = 0;
    if(test(assert_success) != 2) {
        FAIL("assert(1) returned false");
        errc++;
        lerrc++;
    }
    if(test(assert_fail) != 1) {
        FAIL("assert(0) returned true");
        errc++;
        lerrc++;
    }
    if(!lerrc) {
        PASS("assert() works as expected");
    }
}

#ifdef FREESTAND

int errc;

int main() {
    test_ansi_1989_assert_assert();
    printf("\ntotal %d errors\n", errc);
}

#endif /* FREESTAND */
