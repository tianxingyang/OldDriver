#pragma once

#ifndef MY_BINARY_TREE_H_
#define MY_BINARY_TREE_H_

#include "my_binary_tree_node.h"

template <class T>
class MyBinaryTree
{
public:
    MyBinaryTree(int (*CmpFunc)(T node1, T node2));
    ~MyBinaryTree();

    bool Add(MyBinaryTreeNode<T>* node_to_add);
protected:

private:
    int (*CompareFunction)(T node1, T node2);
    MyBinaryTreeNode node;
};

#endif
