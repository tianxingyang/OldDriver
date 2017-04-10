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