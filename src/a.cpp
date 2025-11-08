#include "../include/a.h"
#include <iostream>
#include "../include/b.h"

namespace test_a {
    void func_hehe() {
        std::cout << "hehe" << std::endl;
    }
}

A::A() {
    std::cout << "A created" << std::endl;
}

A::~A() {
    std::cout << "A dead" << std::endl;
}

void A::funcA() {
    std::cout << "hehe" << std::endl;
}

int A::get_value() const {
    return value;
}