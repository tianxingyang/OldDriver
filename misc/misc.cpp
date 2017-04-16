#include "../OldDriver/misc.h"

int main()
{
    BaseClass *baseClassAlpha = new BaseClass;
    delete baseClassAlpha;

    DerivedClass *derivedClassAlpha = new DerivedClass;
    delete derivedClassAlpha;
    return 0;
}