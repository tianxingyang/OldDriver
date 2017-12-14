//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <Python.h>
//#include "misc.h"
//
//
//using namespace std;
//
//int main()
//{
//    /*DerivedClass *derivedClassAlpha = new DerivedClass;
//    derivedClassAlpha->printme();
//    delete derivedClassAlpha;
//
//    int num = 6;
//
//    if ((num & 1) == 0)
//    {
//        std::cout << "num is even" << std::endl;
//    }*/
//    /*int initArray[3] = { 2, 4, 6 };
//    int iTest[3] = { 1, 3, 5 };
//    PrintMe(iTest, 3);
//    memcpy(iTest, initArray, sizeof(iTest));
//    PrintMe(iTest, 3);*/
//
//    /*MyClass classA;
//    int c[5] = { 4, 3, 2, 1, 0 };
//    classA.ChgPtr(c);
//    for (size_t i = 0; i < 5; i++)
//    {
//        cout << c[i] << endl;
//    }
//    classA.ChgPtr(&c);
//    for (size_t i = 0; i < 5; i++)
//    {
//        cout << c[i] << endl;
//    }
//    cout << c << endl;
//    cout << &c << endl;*/
//
//    /*vector<int> vi = { 1, 2, 3, 4 };
//
//    ofstream f("HelloWorld.txt", ios::app);
//    for (vector<int>::iterator iter = vi.begin(); iter != vi.end(); iter++)
//    {
//        f << *iter << endl;
//    }
//    f.close();*/
//
//    /*
//    一定要注意路径！！！！！！！！！！！！！！！！
//    windows + vs的情况下，是脚本在debug目录下，和生成的可执行文件同目录
//    而python脚本中读取的文件，在c++代码的目录下
//    一定要在初始化之后调用这个命令，手动设置路径
//    PyRun_SimpleString("import os");
//    PyRun_SimpleString("sys.path.append('....')");
//
//    */
//
//    //python初始化
//    Py_Initialize();
//    if (Py_IsInitialized() != 1)
//    {
//        return 0;
//    }
//
//    /*PyRun_SimpleString("import os");
//    PyRun_SimpleString("sys.path.append('script')");*/
//
//    PyObject *ptype, *pvalue, *ptraceback;
//    char *pStrErrorMessage = nullptr;
//
//    //加载python模块
//
//    PyObject* moduleName = PyString_FromString("multiple_reward");
//    PyObject* pModule = PyImport_Import(moduleName);
//    if (!pModule)
//    {
//        PyErr_Fetch(&ptype, &pvalue, &ptraceback); 
//        pStrErrorMessage = PyString_AsString(pvalue);
//        ofstream f("PyErr");
//        f << pStrErrorMessage << endl;
//        return 0;
//    }
//
//    //加载python函数
//    PyObject *pFunc;
//    pFunc = PyObject_GetAttrString(pModule, "get_reward_id");
//    if (!pFunc || !PyCallable_Check(pFunc))  // 验证是否加载成功
//    {
//        PyErr_Fetch(&ptype, &pvalue, &ptraceback);
//        pStrErrorMessage = PyString_AsString(pvalue);
//        ofstream f("PyErr");
//        f << pStrErrorMessage << endl;
//        return 0;
//    }
//
//    //一个参数
//    PyObject *pParams = PyTuple_New(1);
//    PyObject *pVal = PyString_FromString("BAEFC81C721E024A9799BAA008D5A27A");
//    PyTuple_SetItem(pParams, 0, pVal);
//
//    PyObject *pRet = PyObject_CallObject(pFunc, pParams);
//
//    long ret = PyInt_AsLong(pRet);
//
//    cout << ret << endl;
//
//    //释放资源
//    Py_Finalize();
//
//    //退出前有个输入，便于检查程序运行情况
//    char closeFlag = 'f';
//    cin >> closeFlag;
//    return 0;
//}
