#pragma once
#include <iostream>

class foo
{
public:
    foo();
    ~foo();

private:
    const static double m1;
    const static int m2 = 3;//����c++Ҫ���κ����͵ľ�̬��Ա������Ҫ�����⸳ֵ����vs�ж�����int�͵������ڸ�ֵ���ᱨ��
};

foo::foo()
{
}

foo::~foo()
{
}

const double foo::m1 = 1.1;//����̬��Ա������ֵ��ʱ�򣬲���Ҫ��static������Ҫconst

/*�����У�ͨ���ᶨ�����ֺ�����һ����ϣ��������ֱ�Ӽ̳ж����޸ĵĺ�����һ����ϣ�������า�ǵĺ���
�����ڻ����ж���ʱһ�㶨��Ϊ�麯��
*/
class BaseClass
{
public:
    BaseClass();
    virtual ~BaseClass();//����ͨ����Ҫ��һ�������������
    void printme() { std::cout << "public: BaseClass.printme()" << std::endl; }
    int memA;
private:
    void printme(bool bSwitch) {}
};

BaseClass::BaseClass()
{
    std::cout << "BaseClass::BaseClass()" << std::endl;
}

BaseClass::~BaseClass()
{
    std::cout << "BaseClass::~BaseClass()" << std::endl;
}
class DerivedClass : public BaseClass
{
public:
    DerivedClass();
    ~DerivedClass();

private:
};

DerivedClass::DerivedClass()
{
}

DerivedClass::~DerivedClass()
{
    std::cout << "DerivedClass::~DerivedClass()" << std::endl;
}