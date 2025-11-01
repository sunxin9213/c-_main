#pragma once

namespace test_a {
    void func_hehe();
}

class B;
class A{
    public:
        void funcA();
        int get_value() const;
        B* member_b;
    private:
        int value = 0;
};