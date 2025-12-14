#pragma once

template <typename T>
class wrapper{
    public:
        wrapper(T const v): value{v} {}
        T const& get() const {return value;}

    private: 
        T value;
};

void test();


/*--------------------------------*/
template <typename T>
class wrapper_copy;//这个类没有定义，但是可以直接在下面函数直接使用

void use_foo(wrapper_copy<int>* ptr);

