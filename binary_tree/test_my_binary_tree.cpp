#include "my_binary_tree.h"
#include "my_binary_tree_node.h"
#include <string>
#include <iostream>

using namespace std;

//class NodeTest : public MyBinaryTreeNode<NodeTest>
//{
//public:
//    NodeTest() { cout << "default constructor" << endl; }
//    NodeTest(int elem1, string elem2);
//    NodeTest(const NodeTest& rv);
//    //NodeTest& operator= (const NodeTest& rv);
//    //virtual MyBinaryTreeNode<NodeTest>& operator= (const NodeTest& rv);
//    ~NodeTest();
//
//private:
//    int elem_a_;
//    string elem_b_;
//};
//
//NodeTest::NodeTest(int elem_int, string elem_string)
//{
//    this->elem_a_ = elem_int;
//    this->elem_b_ = elem_string;
//    cout << "reloaded constructor" << endl;
//}
//
//NodeTest::NodeTest(const NodeTest & rv)
//{
//    this->elem_a_ = rv.elem_a_;
//    this->elem_b_ = rv.elem_b_.data();
//    cout << "copy constructor" << endl;
//}

//MyBinaryTreeNode<NodeTest>& NodeTest::operator=(const NodeTest & rv)
//{
//    this->elem_a_ = rv.elem_a_;
//    this->elem_b_.assign(rv.elem_b_.data());
//    return *this;
//}

//NodeTest::~NodeTest()
//{
//    elem_a_ = 0;
//}

int main()
{
    /*auto tree_root_node = NodeTest(1, "node1");
    auto tree_node_1 = NodeTest(2, "node2");*/
    /*
    �������Ĺ��캯����ʹ�õ�ֵ���ݶ��������ô��ݣ������NodeTest�е�string��Ա�޷�������ֵ���������Ľڵ���
    ��ԭ���ǣ������ڳ�Ա������Ҫ��̬���ٶ��ڴ棬���ʵ��λ������Ҳ���ǰѶ������ֵ��ȫ���Ƹ���һ��������A=B��
    ��ʱ�����B����һ����Ա����ָ���Ѿ��������ڴ棬��A�е��Ǹ���Ա����Ҳָ��ͬһ���ڴ档��ͳ��������⣺��B���ڴ��ͷ��ˣ��磺����������ʱA�ڵ�ָ�����Ұָ���ˣ��������д���
    ���嵽�������£��ǣ�
    ֵ���ݻ��ڴ��ݲ�����ʱ�����һ�ο������������ֵ������һ����ʱ������ȥ����������캯����ʵ���ǽ���ʱ�����ĵ�ַ����binary_tree��root_��
    �����캯������ʱ����ʱ�����������ˣ���string����Ҳ��������������¶������Ľڵ���string��ԱΪ��
    ���������ʹ�����ô��ݣ����Ǵ���һ�����⣬�Ǿ��ǵ��������������ʱ�����е�ֵҲ�ᱻ�޸ģ�
    */
    //auto binary_tree = MyBinaryTree<NodeTest>(&tree_root_node);
    //tree_root_node.~NodeTest();
    //binary_tree.Insert(&tree_node_1);

    char tmp;
    cin >> tmp;

    return 0;
}
