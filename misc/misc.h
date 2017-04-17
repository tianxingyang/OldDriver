/*
切记！不要在头文件中初始化任何值，否则在所有include这个头文件的文件中都会定义并初始化这个变量，造成multiply define
类定义的头文件中不要有输入输出
*/
#pragma once

class foo
{
public:
    foo();
    ~foo();

private:
    const static double m1;
    const static int m2;//按照c++要求，任何类型的静态成员变量都要在类外赋值，但vs有毒啊！const int型的在类内赋值不会报错
    float m3 = 1.5;
};

//const double foo::m1 = 1.1;//给静态成员变量赋值的时候，不需要加static但是需要const

/*
基类中，通常会定义两种函数，一种是希望派生类直接继承而不修改的函数，一种是希望派生类覆盖的函数，后者在基类中定义时一般定义为虚函数
*/
class BaseClass
{
public:
    BaseClass();
    virtual ~BaseClass();//基类通常需要有一个虚的析构函数
    //~BaseClass();
    void printme();
    int memA;

private:
    void printme(bool bSwitch);
};

class DerivedClass : public BaseClass
{
public:
    DerivedClass();
    ~DerivedClass();

private:
};

//虚函数表测试
class VTable
{
public:
    VTable();
    virtual ~VTable();

    virtual void funcBase1();
    virtual void funcBase2();
    virtual void funcBase3();
private:

};