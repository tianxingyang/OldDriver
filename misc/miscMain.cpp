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

    //�˳�ǰ�и����룬���ڼ������������
    bool closeFlag = false;
    std::cin >> closeFlag;
    return 0;
}