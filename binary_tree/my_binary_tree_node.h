#ifndef MY_BINARY_TREE_NODE_H_
#define MY_BINARY_TREE_NODE_H_

template <class T>
class MyBinaryTreeNode
{
public:
    MyBinaryTreeNode<T>() {}
    //virtual MyBinaryTreeNode<T>& operator= (const T& rv) = 0;
    ~MyBinaryTreeNode<T>() {}

public:
    bool IsLeftNull() { return left_ == nullptr; }
    bool IsRightNull() { return right_ == nullptr; }

    MyBinaryTreeNode* GetLeftChild() const { return left_; }
    MyBinaryTreeNode* GetRightChild() const { return right_; }
    void SetLeftChild(MyBinaryTreeNode<T>* left) { left_ = left; }
    void SetRightChild(MyBinaryTreeNode<T>* right) { right_ = right; }

    T GetData() const { return data_; }
    void SetData(const T& data);

private:
    T data_;
    MyBinaryTreeNode* left_ = nullptr;
    MyBinaryTreeNode* right_ = nullptr;
};

template<class T>
inline void MyBinaryTreeNode<T>::SetData(const T & data)
{
    data_ = data;
}

#endif
