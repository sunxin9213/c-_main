#pragma once

template <typename T >
T func_template(T a, T b) {
    return a + b;
}

class A{
    public:
        A();
        ~A();
        void funcA();
        int get_value() const;
    private:
        int value = 0;
};