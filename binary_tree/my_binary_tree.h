#ifndef MY_BINARY_TREE_H_
#define MY_BINARY_TREE_H_

#include <map>
#include "my_binary_tree_node.h"

template <class T>
class MyBinaryTree
{
public:
    MyBinaryTree() : root_(nullptr) {}
    MyBinaryTree(const MyBinaryTree<T>& tree);
    ~MyBinaryTree(){}

protected:
    MyBinaryTreeNode<T>* Copy(MyBinaryTreeNode<T>* root, MyBinaryTreeNode<T>* parent);

private:
    MyBinaryTreeNode<T>* root_;
};

template<class T>
inline MyBinaryTree<T>::MyBinaryTree(const MyBinaryTree<T>& tree)
{
    root_ = Copy(tree.root_, nullptr);
}

template<class T>
inline MyBinaryTreeNode<T>* MyBinaryTree<T>::Copy(MyBinaryTreeNode<T>* root, MyBinaryTreeNode<T>* parent)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    MyBinaryTreeNode<T>* node_temp = new MyBinaryTreeNode<T>;
    node_temp->data_ = root->data_;
    node_temp->parent_ = parent;
    node_temp->left_ = Copy(root->left_, node_temp);
    node_temp->right_ = Copy(root->right_, node_temp);
    return node_temp;
}

#endif
