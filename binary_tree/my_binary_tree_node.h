#pragma once

#ifndef MY_BINARY_TREE_NODE_H_
#define MY_BINARY_TREE_NODE_H_

template <class T>
class MyBinaryTreeNode
{
public:
    MyBinaryTreeNode(T elem_temp);
    ~MyBinaryTreeNode();

    T& GetElem() { return elem; }
    MyBinaryTreeNode* GetRightChild() { return right; }
    MyBinaryTreeNode* GetLeftChild() { return left; }

protected:
private:
    T elem;
    MyBinaryTreeNode* left = nullptr;
    MyBinaryTreeNode* right = nullptr;
};

#endif
