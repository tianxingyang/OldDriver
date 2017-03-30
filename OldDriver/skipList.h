#pragma once
#include <random>
#include <ctime>
#include <cstdlib>

template<typename VALUE, typename KEY, typename COMPARE>
class SkipList
{
public:
    SkipList();
    ~SkipList();
    //向skiplist插入节点并返回后面的值，若插入的key不存在，则返回-1
    int Insert(const VALUE& value, const KEY& key);
    
    //更新skiplist中的元素并且返回更新后的skiplist，若更新的key不存在，则返回-1
    int Update(const VALUE& oldValue, const VALUE& newValue, const KEY& key);

private:
    struct SkipListNode
    {
        VALUE value;
        KEY key;
        SkipListNode* backward;
    };

};

template<typename VALUE, typename KEY, typename COMPARE>
SkipList::SkipList()
{
}

template<typename VALUE, typename KEY, typename COMPARE>
SkipList::~SkipList()
{
}

template<typename VALUE, typename KEY, typename COMPARE>
inline int SkipList<VALUE, KEY, COMPARE>::Insert(const VALUE & value, const KEY & key)
{
    return 0;
}

template<typename VALUE, typename KEY, typename COMPARE>
inline int SkipList<VALUE, KEY, COMPARE>::Update(const VALUE & oldValue, const VALUE & newValue, const KEY & key)
{
    return 0;
}
