#pragma once
#include "total.h"
void test_shared_ptr();

class TEST {
    public:
        TEST(){}
        ~TEST(){}

        void test_weak_ptr() {
           auto a = std::make_shared<A>();
            std::cout << a.use_count() << std::endl;

            std::weak_ptr<A> b{a};
            std::cout << a.use_count() << std::endl;

            if(auto temp = b.lock()) {
                temp->funcA();
            } 
        }

    private:
        int value;


};