/* 
 * asm
 */

void syscall_test();

// unistd
void fork_test();
void pipe_test();

// setjmp
void setjmp_test();
void longjmp_test();
void _setjmp_test();
void _longjmp_test();
void sigsetjmp_test();
void siglongjmp_test();

// time
void gettimeofday_test();

/* 
 * c
 */

// stdlib
void abs_test();

void (*tests[])() = {
    syscall_test, /* syscall() */
    fork_test, /* fork() */
    pipe_test, /* pipe() */
    setjmp_test, /* setjmp() */
    longjmp_test, /* longjmp() */
    _setjmp_test, /* _setjmp() */
    _longjmp_test, /* _longjmp() */
    sigsetjmp_test, /* sigsetjmp() */
    siglongjmp_test, /* siglongjmp() */
    gettimeofday_test, /* gettimeofday() */
    abs_test, /* abs() */
    0
};
