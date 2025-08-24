#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    // 使用列表初始化
    Person person1{"Bob", 60, 1.75};

    std::cout << "Name: " << person1.name << ", Age: " << person1.age 
              << ", Height: " << person1.height << std::endl;
    //merge
    return 0;
}