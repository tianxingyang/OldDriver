#ifndef MY_BINARY_TREE_H_
#define MY_BINARY_TREE_H_

#include <map>
#include "my_binary_tree_node.h"

template <class T>
class MyBinaryTree
{
public:
    MyBinaryTree();
    MyBinaryTree(T* root_node);
    MyBinaryTree(T& root_node);
    ~MyBinaryTree();

public:
    void Insert(T* node_temp);

private:
    T* root_ = nullptr;
};

template<class T>
inline MyBinaryTree<T>::MyBinaryTree()
{
}

template <class T>
inline MyBinaryTree<T>::MyBinaryTree(T* root_node)
{
    root_ = root_node;
}

template <class T>
inline MyBinaryTree<T>::MyBinaryTree(T& root_node)
{
    root_ = &root_node;
}

template <class T>
inline MyBinaryTree<T>::~MyBinaryTree()
{
}

template <class T>
inline void MyBinaryTree<T>::Insert(T* node_temp)
{
    if (node_temp == nullptr)
    {
        return;
    }
    else if (root_ == nullptr)
    {
        root_ = node_temp;
    }
    else if (root_->IsLeftNull())
    {
        Insert(root_->GetLeftChild());
    }
    else if (root_->IsRightNull())
    {
        Insert(root_->GetRightChild());
    }
}
#endif
