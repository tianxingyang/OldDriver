/*
    Date: 4/1/2017
    Description: ģ��star��skipList��ʵ�֣�ʵ���Լ���skipList��
    ������ӵ���������������ݽṹ��
    1. һ�������ж��(Level)���;
    2. ����ĵ�һ��������е�����;
    3. ÿһ�㶼��һ�����������;
    4. ���Ԫ��x�����ڵ�i�㣬�����б�iС�Ĳ㶼Ӧ�ð���x;
    5. ��i��ͨ��һ��downָ��ָ����һ����ӵ����ֵͬ��Ԫ��;
    6. ��ÿһ���У�-1��1����Ԫ�ض�����(�ֱ��ʾINT_MIN��INT_MAX);
    7. TOPָ��ָ����߲�ĵ�һ��Ԫ�ء�
    Author: VitoYang
*/
#pragma once
//���ϵ�skipList�汾����Ϊ�򵥣��ʺ�ѧϰ
#include <random>
#include <ctime>
#include <cstdlib>

typedef struct nodeStructure
{
    int key;
    int value;

    struct nodeStructure *forward[1];
}nodeStructure;

typedef struct skiplist
{
    int level;

    nodeStructure *header;
}skiplist;

nodeStructure* createNode(int level, int value)
{
    nodeStructure *ns = (nodeStructure *)
}
//star���skipList��ӵ�кܺõ���չ�ԣ���Ϊ����
//#include <random>
//#include <ctime>
//#include <cstdlib>
//
////ģ�廯skiplist����ʵ�ָ��õ���չ��
//template<typename VALUE, typename KEY, typename COMPARE>
//class SkipList
//{
//public:
//    SkipList();
//    ~SkipList();
//    //��skiplist����ڵ㲢���غ����ֵ���������key�����ڣ��򷵻�-1
//    int Insert(const VALUE& value, const KEY& key);
//
//    //����skiplist�е�Ԫ�ز��ҷ��ظ��º��skiplist�������µ�key�����ڣ��򷵻�-1
//    int Update(const VALUE& oldValue, const VALUE& newValue, const KEY& key);
//
//private:
//    struct SkipListNode
//    {
//        VALUE value;
//        KEY key;
//        SkipListNode* backward;
//        struct SkipListLevel
//        {
//            SkipListNode* forward;
//            int span;
//            SkipListLevel() : forward(NULL), span(0) {}
//        };
//        SkipListLevel* level;
//
//        SkipListNode() :backwardf(NULL), level(NULL) {}
//        ~SkipListNode()
//        {
//        }
//    };
//};
//
//template<typename VALUE, typename KEY, typename COMPARE>
//SkipList::SkipList()
//{
//}
//
//template<typename VALUE, typename KEY, typename COMPARE>
//SkipList::~SkipList()
//{
//}
//
//template<typename VALUE, typename KEY, typename COMPARE>
//inline int SkipList<VALUE, KEY, COMPARE>::Insert(const VALUE & value, const KEY & key)
//{
//    return 0;
//}
//
//template<typename VALUE, typename KEY, typename COMPARE>
//inline int SkipList<VALUE, KEY, COMPARE>::Update(const VALUE & oldValue, const VALUE & newValue, const KEY & key)
//{
//    return 0;
//}
