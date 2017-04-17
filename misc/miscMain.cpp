#include "misc.h"
#include <iostream>

int main()
{
    DerivedClass *derivedClassAlpha = new DerivedClass;
    derivedClassAlpha->printme();
    delete derivedClassAlpha;

    int num = 6;

    if ((num & 1) == 0)
    {
        std::cout << "num is even" << std::endl;
    }

    //退出前有个输入，便于检查程序运行情况
    bool closeFlag = false;
    std::cin >> closeFlag;
    return 0;
}