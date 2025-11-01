#include "../include/a.h"
#include <iostream>

void A::funcA() {
    std::cout << "function A" << std::endl;
}

int A::get_value() const {
    return value;
}