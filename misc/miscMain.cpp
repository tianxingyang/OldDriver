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
//    һ��Ҫע��·����������������������������������
//    windows + vs������£��ǽű���debugĿ¼�£������ɵĿ�ִ���ļ�ͬĿ¼
//    ��python�ű��ж�ȡ���ļ�����c++�����Ŀ¼��
//    һ��Ҫ�ڳ�ʼ��֮������������ֶ�����·��
//    PyRun_SimpleString("import os");
//    PyRun_SimpleString("sys.path.append('....')");
//
//    */
//
//    //python��ʼ��
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
//    //����pythonģ��
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
//    //����python����
//    PyObject *pFunc;
//    pFunc = PyObject_GetAttrString(pModule, "get_reward_id");
//    if (!pFunc || !PyCallable_Check(pFunc))  // ��֤�Ƿ���سɹ�
//    {
//        PyErr_Fetch(&ptype, &pvalue, &ptraceback);
//        pStrErrorMessage = PyString_AsString(pvalue);
//        ofstream f("PyErr");
//        f << pStrErrorMessage << endl;
//        return 0;
//    }
//
//    //һ������
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
//    //�ͷ���Դ
//    Py_Finalize();
//
//    //�˳�ǰ�и����룬���ڼ������������
//    char closeFlag = 'f';
//    cin >> closeFlag;
//    return 0;
//}
