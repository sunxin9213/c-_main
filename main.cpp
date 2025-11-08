#include "../include/test.h"

using A_PTR = std::unique_ptr<A>;
using A_PTRS = std::vector<A_PTR>;

int main() {
    TEST test_a;
    TEST test_c;

    test_c = std::move(test_a);
    //这种先move，但是还能使用 =test_a是正常的，因为move只是将test_a转换成右值引用，而不是彻底销毁，test_a
    //但是尽量不使用move后的对象，因为可能状态是未知的，如果使用接可能重置
    TEST test_b = test_a;


    TEST test_d = std::move(test_b);
    return 0;
}