//#pragma once
//
////1.0版本，未完成，感觉结构有问题，删除，重构
//
//#ifndef MY_BINARY_TREE_H_
//#define MY_BINARY_TREE_H_
//
//#include "my_binary_tree_node.h"
//
//template <class T>
//class MyBinaryTree
//{
//public:
//    MyBinaryTree();
//    ~MyBinaryTree() {}
//
//    bool Add(MyBinaryTreeNode<T>* node_to_add);
//
//    void PreOrder(const MyBinaryTreeNode& root_node);
//protected:
//
//private:
//    MyBinaryTreeNode<T>* root_node = nullptr;
//};
//
//template<class T>
//MyBinaryTree<T>::MyBinaryTree()
//{
//}
//
//template<class T>
//bool MyBinaryTree<T>::Add(MyBinaryTreeNode<T>* node_to_add)
//{
//    
//}
//
//template<class T>
//inline void MyBinaryTree<T>::PreOrder(const MyBinaryTree& tree)
//{
//    if (tree.root_node == nullptr)
//    {
//        return;
//    }
//    PreOrder(this.root_node->GetLeftChild());
//}
//#endif
