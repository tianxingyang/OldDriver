#include "misc.h"
#include <iostream>

using namespace std;
//
///*
//为复杂的声明定义一个新的简单的别名。方法是：在原来的声明里逐步用别名替换一部
//分复杂声明，如此循环，把带变量名的部分留到最后替换，得到的就是原声明的最简化
//版。举例：
//原声明：void (*b[10]) (void (*)());
//变量名为b，先替换右边部分括号里的，pFunParam为别名一：
//typedef void (*pFunParam)();
//再替换左边的变量b，pFunx为别名二：
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
//const double foo::m1 = 1.1;//给静态成员变量赋值的时候，不需要加static但是需要const
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

void PrintMe(int intArray[], int length)
{
    for (int i = 0; i != length; ++i)
    {
        cout << intArray[i] << endl;
    }
}
