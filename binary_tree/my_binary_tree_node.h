#pragma once

#ifndef MY_BINARY_TREE_NODE_H_
#define MY_BINARY_TREE_NODE_H_

template<class T>
class MyBinaryTreeNode
{
public:
    MyBinaryTreeNode();
    MyBinaryTreeNode(const T elem_temp);
    ~MyBinaryTreeNode();

public:
    bool IsLeftNull() { return left_ == nullptr; }
    bool IsRightNull() { return right_ == nullptr; }

    MyBinaryTreeNode* GetLeftChild() { return left_; }
    MyBinaryTreeNode* GetRightChild() { return right_; }

private:
    T elem_;
    MyBinaryTreeNode* left_ = nullptr;
    MyBinaryTreeNode* right_ = nullptr;
};

template<class T>
inline MyBinaryTreeNode<T>::MyBinaryTreeNode()
{
    left_ = nullptr;
    right_ = nullptr;
}

template<class T>
inline MyBinaryTreeNode<T>::MyBinaryTreeNode(const T elem_temp)
{
    this->elem_ = elem_temp;
    left_ = nullptr;
    right_ = nullptr;
}

template<class T>
inline MyBinaryTreeNode<T>::~MyBinaryTreeNode()
{
}

#endif
