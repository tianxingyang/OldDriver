#include "misc.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    /*DerivedClass *derivedClassAlpha = new DerivedClass;
    derivedClassAlpha->printme();
    delete derivedClassAlpha;

    int num = 6;

    if ((num & 1) == 0)
    {
        std::cout << "num is even" << std::endl;
    }*/
    int initArray[3] = { 2, 4, 6 };
    int iTest[3] = { 1, 3, 5 };
    PrintMe(iTest, 3);
    memcpy(iTest, initArray, sizeof(iTest));
    PrintMe(iTest, 3);

    //�˳�ǰ�и����룬���ڼ������������
    char closeFlag = 'f';
    std::cin >> closeFlag;
    return 0;
}
