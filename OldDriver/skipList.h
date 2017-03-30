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
    //向skiplist插入节点并返回后面的值
    int Insert(const VALUE& value, const KEY& key);
    
    //更新skiplist中的元素并且

private:

};

SkipList::SkipList()
{
}

SkipList::~SkipList()
{
}