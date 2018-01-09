#include "my_binary_tree.h"
#include "my_binary_tree_node.h"
#include <string>
#include <iostream>

using namespace std;

class NodeTest : public MyBinaryTreeNode<NodeTest>
{
public:
    NodeTest() { cout << "default constructor" << endl; }
    NodeTest(int elem1, string elem2);
    NodeTest(const NodeTest& rv);
    //NodeTest& operator= (const NodeTest& rv);
    //virtual MyBinaryTreeNode<NodeTest>& operator= (const NodeTest& rv);
    ~NodeTest();

private:
    int elem_a_;
    string elem_b_;
};

NodeTest::NodeTest(int elem_int, string elem_string)
{
    this->elem_a_ = elem_int;
    this->elem_b_ = elem_string;
    cout << "reloaded constructor" << endl;
}

NodeTest::NodeTest(const NodeTest & rv)
{
    this->elem_a_ = rv.elem_a_;
    this->elem_b_ = rv.elem_b_.data();
    cout << "copy constructor" << endl;
}

//MyBinaryTreeNode<NodeTest>& NodeTest::operator=(const NodeTest & rv)
//{
//    this->elem_a_ = rv.elem_a_;
//    this->elem_b_.assign(rv.elem_b_.data());
//    return *this;
//}

NodeTest::~NodeTest()
{
    elem_a_ = 0;
}

int main()
{
    auto tree_root_node = NodeTest(1, "node1");
    auto tree_node_1 = NodeTest(2, "node2");
    /*
    如果这里的构造函数，使用的值传递而不是引用传递，会造成NodeTest中的string成员无法正常赋值到二叉树的节点中
    其原因是，当类内成员变量需要动态开辟堆内存，如果实行位拷贝，也就是把对象里的值完全复制给另一个对象，如A=B。
    这时，如果B中有一个成员变量指针已经申请了内存，那A中的那个成员变量也指向同一块内存。这就出现了问题：当B把内存释放了（如：析构），这时A内的指针就是野指针了，出现运行错误。
    具体到这个情况下，是：
    值传递会在传递参数的时候进行一次拷贝，将传入的值拷贝到一个临时变量中去，而这个构造函数的实现是将临时变量的地址赋给binary_tree的root_，
    当构造函数结束时，临时变量被析构了，而string对象也会进行析构，导致二叉树的节点中string成员为空
    解决方案：使用引用传递（还是存在一个问题，那就是当这个对象被析构的时候，树中的值也会被修改）
    */
    auto binary_tree = MyBinaryTree<NodeTest>(&tree_root_node);
    //tree_root_node.~NodeTest();
    //binary_tree.Insert(&tree_node_1);

    char tmp;
    cin >> tmp;

    return 0;
}
