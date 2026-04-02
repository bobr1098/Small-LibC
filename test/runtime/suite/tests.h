void stack_chk_test();
void __divdi3_test();
void __divsi3_test();
void __fixdfdi_test();
void _c_startup_test();

void (*tests[])() = {
    _c_startup_test,
    stack_chk_test,
    __divdi3_test,
    __divsi3_test,
    __fixdfdi_test,
    0
};

