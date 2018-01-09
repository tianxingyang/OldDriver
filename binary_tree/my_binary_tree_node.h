#ifndef MY_BINARY_TREE_NODE_H_
#define MY_BINARY_TREE_NODE_H_

enum ChildId
{
    kLeftChild = 0,
    kRightChild = 1,
};

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
    void SetParent(MyBinaryTreeNode<T>* parent) { parent_ = parent; }

    T GetData() const { return data_; }
    void SetData(const T& data);

private:
    T data_;
    MyBinaryTreeNode* left_;
    MyBinaryTreeNode* right_;
    MyBinaryTreeNode* parent_;
};

template<class T>
inline void MyBinaryTreeNode<T>::SetData(const T & data)
{
    data_ = data;
}

#endif
