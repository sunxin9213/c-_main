#pragma once
#include "total.h"
void test_shared_ptr();

class TEST {
    public:
        TEST() = default;
        ~TEST(){print_str("dead");}

        TEST(const TEST& other) {//拷贝构造函数
            print_str("调用拷贝构造函数");
        }

        TEST(TEST && other) {//移动构造函数，把data从其他对象移动到当前
            print_str("调用移动构造函数");
        }

        TEST& operator=(const TEST& other) {//拷贝赋值运算符
            print_str("调用拷贝赋值运算符");
            return *this;
        }

        TEST& operator=(TEST&& other) {//移动赋值运算符
            //operator=需要一个显式参数（右操作数），而左操作数是隐式的 this指针指向的对象
            print_str("调用移动赋值运算符");
            return *this;
        }

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

