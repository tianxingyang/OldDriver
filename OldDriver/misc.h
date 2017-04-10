#pragma once

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
