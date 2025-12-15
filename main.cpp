// #include "../include/test.h"
// #include "../include/class_template.h"
#include <string>
#include <string.h>
#include <iostream>
//右值引用主要用来延长右值的声明周期
//下面是一个包装器的用法，可用于延迟数据处理，
template <typename T> 
class MoveWrapper {
    public:
        MoveWrapper(T&& data): data_(std::move(data)) {
            std::cout << "MoveWrapper create!" << std::endl;
        }

        const T& get() const {return data_;}

    private:
        mutable T data_;
};

void test1() {
    //std::move会将str的资源拿到，并将str置空
    std::string str = "Hello, World!";
    std::cout << str << std::endl;
    MoveWrapper<std::string> wrapper(std::move(str));
    std::cout << str << std::endl;
    std::cout << wrapper.get() << std::endl;
}

class Resource {
    public:
        Resource(){std::cout << "Resource live" << std::endl;}
        ~Resource(){std::cout << "Resource dead" << std::endl;}
        Resource(const Resource&) {std::cout << "Resource copy" << std::endl;}
};

Resource createResource() {
    return Resource();
}

void test2() {
    // createResource();//对象创建完立即销毁，立马析构
    // std::cout << "haha" << std::endl;

    // Resource r1 = createResource();//对象创建完后，在test2()结束之后才析构，发生的是拷贝构造
    // std::cout << "haha" << std::endl;

    // const Resource &r1 = createResource();//同上，对象创建完后，在test2()结束之后才析构
    // std::cout << "haha" << std::endl;

    //Resource & r1 = createResource();//编译报错，不能将右值绑定在非const的左值引用

    // Resource &&r1 = createResource();//对象创建完后，在test2()结束之后才析构
    // std::cout << "haha" << std::endl;

    // Resource && r3 = createResource();
    // Resource r4 = std::move(r3);//在这里执行的实际是拷贝构造函数
    // std::cout << "haha" << std::endl;

    // Resource && r3 = createResource();//一次构造，一次析构，只产生了一个对象
    // const Resource & r4 = std::move(r3);
}

int main() {
    //test1();
    test2();
    return 0;
}

//总结：
//左值引用只能引用左值，不能用来引用右值
//但是const左值引用既可以引用左值也可以引用右值

//右值引用只能用来引用右值，不能引用左值
//但是右值引用可以引用move以后的左值


/*
#include <iostream>
#include <utility>  // std::move

int main() {
    int a = 10;
    
    // 右值引用只能绑定到右值
    int&& r1 = 10;        // 正确：10是右值
    
    // int&& r2 = a;      // 错误：a是左值，不能直接绑定到右值引用
    
    // 但是可以通过std::move将左值转换为右值引用
    int&& r3 = std::move(a);  // 正确：std::move(a)返回右值引用
    
    std::cout << "a = " << a << std::endl;      // a的值可能被改变！
    std::cout << "r3 = " << r3 << std::endl;    // r3现在是a的别名
    
    // 注意：使用std::move后，a处于"被移动"状态
    // 技术上a仍然有效，但它的值是不确定的
    // 实际编程中，我们应该假设a不再可用，除非重新赋值
    
    // const右值引用
    const int&& r4 = 20;  // 正确：const右值引用
    // r4 = 30;            // 错误：const引用不能修改
    
    // 右值引用可以绑定到哪些表达式？
    int x = 5, y = 3;
    // int&& r5 = x + y;    // 正确：表达式x+y是右值
    // int&& r6 = x++;      // 正确：后置++返回右值
    // int&& r7 = ++x;      // 错误：前置++返回左值
    
    return 0;
}
*/
