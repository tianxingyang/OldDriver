#include "my_binary_tree.h"

template <class T>
MyBinaryTree<T>::MyBinaryTree(int(*CmpFunc)(T node1, T node2))
{
}

template <class T>
MyBinaryTree<T>::~MyBinaryTree()
{
}

template<class T>
bool MyBinaryTree<T>::Add(MyBinaryTreeNode<T>* node_to_add)
{
    if (this->node.GetLeftChild() == nullptr)
    {
        this->node.GetRightChild() = node_to_add;
    }
    return false;
}
