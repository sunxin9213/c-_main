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

        TEST(TEST && other) noexcept {//移动构造函数，把data从其他对象移动到当前
            print_str("调用移动构造函数");
        }

        TEST& operator=(const TEST& other) {//拷贝赋值运算符
            print_str("调用拷贝赋值运算符");
            return *this;
        }

        TEST& operator=(TEST&& other) noexcept {//移动赋值运算符
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

// 五大原则（Rule of Five）
// 当一个类需要手动管理资源时，应该正确定义以下五个特殊成员函数：
// 1. 析构函数（Destructor）
// 2. 拷贝构造函数（Copy Constructor）
// 3. 拷贝赋值运算符（Copy Assignment Operator）
// 4. 移动构造函数（Move Constructor）
// 5. 移动赋值运算符（Move Assignment Operator）
//五大原则，需要手动管理资源的情况，可参考如下类

//零原则：也就是尽量使用智能指针和标准库去管理资源，而不是使用五大原则，这样代码更简洁且无异常
class RuleOfFive {
private:
    int* data;
    size_t size;
    
public:
    // 1. 构造函数
    RuleOfFive(size_t s = 0) : size(s), data(size ? new int[size] : nullptr) {}
    
    // 2. 析构函数
    ~RuleOfFive() {
        delete[] data;
    }
    
    // 3. 拷贝构造函数
    RuleOfFive(const RuleOfFive& other) 
        : size(other.size), data(size ? new int[size] : nullptr) {
        std::copy(other.data, other.data + size, data);
    }
    
    // 4. 拷贝赋值运算符
    RuleOfFive& operator=(const RuleOfFive& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = size ? new int[size] : nullptr;
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    
    // 5. 移动构造函数
    RuleOfFive(RuleOfFive&& other) noexcept 
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }
    
    // 6. 移动赋值运算符
    RuleOfFive& operator=(RuleOfFive&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

