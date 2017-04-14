#pragma once
#include <iostream>

class foo
{
public:
    foo();
    ~foo();

private:
    const static double m1;
    const static int m2 = 3;
};

foo::foo()
{
}

foo::~foo()
{
}

const double foo::m1 = 1.1;//给静态成员变量赋值的时候，不需要加static但是需要const

class BasicClass
{
public:
    BasicClass();
    ~BasicClass();
    void printme() { std::cout << "public: BasicClass.printme()" << std::endl; }

private:

};

BasicClass::BasicClass()
{
}

BasicClass::~BasicClass()
{
}

class classtest : public BasicClass
{
public:
    classtest();
    ~classtest();

private:

};

classtest::classtest()
{
}

classtest::~classtest()
{
}