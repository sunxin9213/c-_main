#include "../include/test.h"

using A_PTR = std::unique_ptr<A>;
using A_PTRS = std::vector<A_PTR>;

int main() {
    TEST test;
    test.test_weak_ptr();

    return 0;
}