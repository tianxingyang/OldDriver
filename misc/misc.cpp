#include "misc.h"
#include <iostream>

using namespace std;
//
//
//Ϊ���ӵ���������һ���µļ򵥵ı����������ǣ���ԭ�������������ñ����滻һ��
//�ָ������������ѭ�����Ѵ��������Ĳ�����������滻���õ��ľ���ԭ���������
//�档������
//ԭ������void (*b[10]) (void (*)());
//������Ϊb�����滻�ұ߲���������ģ�pFunParamΪ����һ��
//typedef void (*pFunParam)();
//���滻��ߵı���b��pFunxΪ��������
//typedef void (*pFunx)(pFunParam);
//*/
//typedef void(*Fun) (void);
//
////int main()
////{
////    BaseClass *baseClassAlpha = new BaseClass;
////    baseClassAlpha->memA = 1;
////    (*baseClassAlpha).memA = 2;
////    baseClassAlpha->printme();
////    delete baseClassAlpha;
////
////    DerivedClass *derivedClassAlpha = new DerivedClass;
////    delete derivedClassAlpha;
////    return 0;
////}
//
//const double foo::m1 = 1.1;//����̬��Ա������ֵ��ʱ�򣬲���Ҫ��static������Ҫconst
//const int foo::m2 = 2;
//
//foo::foo()
//{
//}
//
//foo::~foo()
//{
//}
//
//BaseClass::BaseClass()
//{
//    std::cout << "BaseClass::BaseClass()" << std::endl;
//}
//
//BaseClass::~BaseClass()
//{
//    std::cout << "BaseClass::~BaseClass()" << std::endl;
//}
//
//void BaseClass::printme()
//{
//    std::cout << "BaseClass::printme()" << std::endl;
//}
//
//void BaseClass::printme(bool bSwitch)
//{
//    if (bSwitch == true)
//    {
//        std::cout << "private BaseClass::printme()" << std::endl;
//    }
//}
//
//DerivedClass::DerivedClass()
//{
//}
//
//DerivedClass::~DerivedClass()
//{
//    std::cout << "DerivedClass::~DerivedClass()" << std::endl;
//}
//
//VTable::VTable()
//{
//}
//
//VTable::~VTable()
//{
//}
//
//void VTable::funcBase1()
//{
//    std::cout << "VTable::funcBase1" << std::endl;
//}
//
//void VTable::funcBase2()
//{
//    std::cout << "VTable::funcBase2" << std::endl;
//}
//
//void VTable::funcBase3()
//{
//    std::cout << "VTable::funcBase3()" << std::endl;
//}

//void PrintMe(int intArray[], int length)
//{
//    for (int i = 0; i != length; ++i)
//    {
//        cout << intArray[i] << endl;
//    }
//}
