// #include "../include/test.h"
// #include "../include/class_template.h"
#include <string>
#include <string.h>

//嵌套类的使用如下
//如果想class B的声明和定义分开，也就是B使用前向声明，然后B在类外定义，那么对于成员变量data_b就应该使用指针
//模板类在编译过程中，不会使用类型检查，因此可以不使用第2点

class A{
    public:
        class B{
            friend A;
            public:
                int pub_b;
            protected:
                int pro_b;
            private:
                int pri_b;
        };

        int pub_a;
        B data_b;

        void set() {
            data_b.pro_b = 0;
            data_b.pri_b = 0;
        }

    protected:
        int pro_a;

    private:
        int pri_a;

};

int main() {
        A test_a;
        test_a.set();
        
    return 0;
}