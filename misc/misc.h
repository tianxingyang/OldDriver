/*
�мǣ���Ҫ��ͷ�ļ��г�ʼ���κ�ֵ������������include���ͷ�ļ����ļ��ж��ᶨ�岢��ʼ��������������multiply define
�ඨ���ͷ�ļ��в�Ҫ���������
*/
#pragma once

class foo
{
public:
    foo();
    ~foo();

private:
    const static double m1;
    const static int m2;//����c++Ҫ���κ����͵ľ�̬��Ա������Ҫ�����⸳ֵ����vs�ж�����const int�͵������ڸ�ֵ���ᱨ��
    float m3 = 1.5;
};

//const double foo::m1 = 1.1;//����̬��Ա������ֵ��ʱ�򣬲���Ҫ��static������Ҫconst

/*
�����У�ͨ���ᶨ�����ֺ�����һ����ϣ��������ֱ�Ӽ̳ж����޸ĵĺ�����һ����ϣ�������า�ǵĺ����������ڻ����ж���ʱһ�㶨��Ϊ�麯��
*/
class BaseClass
{
public:
    BaseClass();
    virtual ~BaseClass();//����ͨ����Ҫ��һ�������������
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

//�麯�������
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