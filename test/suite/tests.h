void fork_test();
void pipe_test();
void abs_test();

void (*tests[])() = {
    fork_test, /* fork() */
    pipe_test, /* pipe() */
    abs_test, /* abs() */
    0
};
