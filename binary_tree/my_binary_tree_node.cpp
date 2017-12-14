#include "my_binary_tree_node.h"

template<class T>
inline MyBinaryTreeNode<T>::MyBinaryTreeNode(T elem_temp)
{
    this->elem = elem_temp;
}

template<class T>
MyBinaryTreeNode<T>::~MyBinaryTreeNode()
{
}
