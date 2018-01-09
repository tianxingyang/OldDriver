#ifndef MY_BINARY_TREE_NODE_H_
#define MY_BINARY_TREE_NODE_H_

#include "common/common.h"

template <class T>
class MyBinaryTreeNode
{
public:
    MyBinaryTreeNode():left_(nullptr), right_(nullptr), parent_(nullptr) {}
    MyBinaryTreeNode(T data, MyBinaryTreeNode<T>* left_child = nullptr, MyBinaryTreeNode<T>* right_child = nullptr, MyBinaryTreeNode<T>* parent = nullptr): 
        left_(left_child), right_(right_child), parent_(parent) {}
    //virtual MyBinaryTreeNode<T>& operator= (const T& rv) = 0;
    ~MyBinaryTreeNode() {}

public:
    bool IsLeftNull() { return left_ == nullptr; }
    bool IsRightNull() { return right_ == nullptr; }

    MyBinaryTreeNode* GetLeftChild() const { return left_; }
    MyBinaryTreeNode* GetRightChild() const { return right_; }
    MyBinaryTreeNode* GetParent() const { return parent_; }
    void SetLeftChild(MyBinaryTreeNode<T>* left) { left_ = left; }
    void SetRightChild(MyBinaryTreeNode<T>* right) { right_ = right; }
    void SetParent(MyBinaryTreeNode<T>* parent, olddriver::ChildId child_id);

    T GetData() const { return data_; }
    void SetData(const T& data);

private:
    T data_;
    MyBinaryTreeNode* left_;
    MyBinaryTreeNode* right_;
    MyBinaryTreeNode* parent_;
};

template<class T>
inline void MyBinaryTreeNode<T>::SetParent(MyBinaryTreeNode<T>* parent, olddriver::ChildId child_id)
{
    if (parent == nullptr)
    {
        return;
    }
    switch (child_id)
    {
    case olddriver::kLeftChild:
        parent_ = parent;
        parent->left_ = this;
        break;
    case olddriver::kRightChild:
        parent_ = parent;
        parent->right_ = this;
        break;
    default:
        break;
    }
}

template<class T>
inline void MyBinaryTreeNode<T>::SetData(const T & data)
{
    data_ = data;
}

#endif
