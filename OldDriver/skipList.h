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
    //��skiplist����ڵ㲢���غ����ֵ
    int Insert(const VALUE& value, const KEY& key);
    
    //����skiplist�е�Ԫ�ز���

private:

};

SkipList::SkipList()
{
}

SkipList::~SkipList()
{
}