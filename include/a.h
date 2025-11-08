#pragma once

class A{
    public:
        A();
        ~A();
        void funcA();
        int get_value() const;
    private:
        int value = 0;
};