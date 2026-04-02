void stack_chk_test();
void __divdi3_test();
void __divsi3_test();
void __fixdfdi_test();
void _c_startup_test();
void __fixunsdfdi_test();
void __floatdidf_test();
void __floatundidf_test();
void __moddi3_test();
void __modsi3_test();

void (*tests[])() = {
    _c_startup_test,
    stack_chk_test,
    __divdi3_test,
    __divsi3_test,
    __fixdfdi_test,
    __fixunsdfdi_test,
    __floatdidf_test,
    __floatundidf_test,
    __moddi3_test,
    __modsi3_test,
    0
};

