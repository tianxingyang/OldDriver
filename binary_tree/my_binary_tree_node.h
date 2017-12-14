#pragma once

//1.0�汾��δ��ɣ��о��ṹ�����⣬ɾ�����ع�

#ifndef MY_BINARY_TREE_NODE_H_
#define MY_BINARY_TREE_NODE_H_

template <class T>
class MyBinaryTreeNode
{
public:
    MyBinaryTreeNode() {}
    MyBinaryTreeNode(T elem_temp);
    ~MyBinaryTreeNode();

    T& GetElem() { return elem; }

    void SetRightChild(MyBinaryTreeNode* right_temp) { right = right_temp; }
    void SetLeftChild(MyBinaryTreeNode* left_temp) { left = left_temp; }
    MyBinaryTreeNode* &GetRightChild() { return right; }
    MyBinaryTreeNode* &GetLeftChild() { return left; }

protected:
private:
    T elem;
    MyBinaryTreeNode* left = nullptr;
    MyBinaryTreeNode* right = nullptr;
};

template<class T>
MyBinaryTreeNode<T>::MyBinaryTreeNode(T elem_temp)
{
    this->elem = elem_temp;
}

template<class T>
MyBinaryTreeNode<T>::~MyBinaryTreeNode()
{
}

#endif
