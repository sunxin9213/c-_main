#include "../include/a.h"
#include <iostream>
#include "../include/b.h"

namespace test_a {
    void func_hehe() {
        std::cout << "hehe" << std::endl;
    }
}


void A::funcA() {
    member_b->funcB();
}

int A::get_value() const {
    return value;
}