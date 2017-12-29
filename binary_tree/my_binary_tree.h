#pragma once

#ifndef MY_BINARY_TREE_H_
#define MY_BINARY_TREE_H_

#include "my_binary_tree_node.h"
#include <map>

template<class T>
class MyBinaryTree
{
public:
    MyBinaryTree();
    MyBinaryTree(MyBinaryTreeNode<T>* root_node);
    MyBinaryTree(MyBinaryTreeNode<T> root_node);
    ~MyBinaryTree();

public:
    void Insert(MyBinaryTreeNode<T>* node_temp);

private:
    MyBinaryTreeNode<T>* root_ = nullptr;
};

template<class T>
inline MyBinaryTree<T>::MyBinaryTree()
{
    root_ = nullptr;
}

template<class T>
inline MyBinaryTree<T>::MyBinaryTree(MyBinaryTreeNode<T>* root_node)
{
    root_ = root_node;
}

template<class T>
inline MyBinaryTree<T>::MyBinaryTree(MyBinaryTreeNode<T> root_node)
{
    root_ = &root_node;
}

template<class T>
inline MyBinaryTree<T>::~MyBinaryTree()
{
}

template<class T>
inline void MyBinaryTree<T>::Insert(MyBinaryTreeNode<T>* node_temp)
{
    if (node_temp == nullptr)
    {
        return;
    }
    else if (this->root_ == nullptr)
    {
        this->root_ = node_temp;
    }
    else if (this->root_->IsLeftNull())
    {
        auto left_child = MyBinaryTree<T>(this->root_->GetLeftChild());
        left_child.Insert(node_temp);
    }
    else if (this->root_->IsRightNull())
    {
        auto right_child = MyBinaryTree<T>(this->root_->GetRightChild());
        right_child.Insert(node_temp);
    }
}
#endif
