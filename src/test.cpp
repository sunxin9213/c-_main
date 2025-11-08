#include "../include/test.h"
#include <memory>

void test_shared_ptr() {
    std::shared_ptr<A> a = std::make_shared<A>();
    //A * a_address = a.get();
    std::cout <<  a.get() << std::endl;
}

