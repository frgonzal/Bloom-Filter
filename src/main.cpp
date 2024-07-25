#include <iostream>
#include "../headers/db/DataBase.hpp"
#include "vector"
#include "iostream"



class A {
public:
    A(int x) : x(x) {
        foo();
    };

    A() : x(0) {
        foo();
    };

    virtual void foo() const {
        std::cout << "A " << x << std::endl;
    };

private:
    int x;
};

class B : public A {
public:
    B(int x) : x(x) {
        foo();
    };

    void foo() const override {
        std::cout << "B " << x << std::endl;
    }

private:
    int x;
};


int main(int argc, char* argv[]){

    A* b = new B(100);

    return 0;
}