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
    //��skiplist����ڵ㲢���غ����ֵ���������key�����ڣ��򷵻�-1
    int Insert(const VALUE& value, const KEY& key);
    
    //����skiplist�е�Ԫ�ز��ҷ��ظ��º��skiplist�������µ�key�����ڣ��򷵻�-1
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
