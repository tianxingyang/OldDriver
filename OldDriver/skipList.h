/*
    Date: 4/1/2017
    Description: 模仿star的skipList的实现，实现自己的skipList。
    跳表，是拥有以下特征的数据结构：
    1. 一个跳表有多层(Level)组成;
    2. 跳表的第一层包含所有的数据;
    3. 每一层都是一个有序的链表;
    4. 如果元素x出现在第i层，则所有比i小的层都应该包含x;
    5. 第i层通过一个down指针指向下一层中拥有相同值的元素;
    6. 在每一层中，-1和1两个元素都出现(分别表示INT_MIN和INT_MAX);
    7. TOP指针指向最高层的第一个元素。
    Author: VitoYang
*/
#pragma once
//网上的skipList版本，较为简单，适合学习
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
//star版的skipList，拥有很好的拓展性，较为复杂
//#include <random>
//#include <ctime>
//#include <cstdlib>
//
////模板化skiplist，以实现更好的拓展性
//template<typename VALUE, typename KEY, typename COMPARE>
//class SkipList
//{
//public:
//    SkipList();
//    ~SkipList();
//    //向skiplist插入节点并返回后面的值，若插入的key不存在，则返回-1
//    int Insert(const VALUE& value, const KEY& key);
//
//    //更新skiplist中的元素并且返回更新后的skiplist，若更新的key不存在，则返回-1
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
