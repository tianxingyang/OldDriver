#include "my_binary_tree.h"
#include "my_binary_tree_node.h"
#include <string>
#include <iostream>

using namespace std;

class NodeTest
{
public:
    NodeTest() { cout << "default constructor" << endl; }
    NodeTest(int elem1, string elem2);
    NodeTest(const NodeTest& rv);
    ~NodeTest();

    int& GetElemA() { return elem_a; }
    string& GetElemB() { return elem_b; }
protected:
private:
    int elem_a;
    string elem_b;
};

NodeTest::NodeTest(int elem_int, string elem_string)
{
    this->elem_a = elem_int;
    this->elem_b = elem_string;
    cout << "reloaded constructor" << endl;
}

NodeTest::NodeTest(const NodeTest & rv)
{
    this->elem_a = rv.elem_a;
    this->elem_b = rv.elem_b;
    cout << "copy constructor" << endl;
}

NodeTest::~NodeTest()
{

}

int main()
{
    auto node1 = NodeTest(1, "node1");
    auto node2 = NodeTest(2, "node2");

    auto tree_root_node = MyBinaryTreeNode<NodeTest>(node1);
    auto tree_node_1 = MyBinaryTreeNode<NodeTest>(node2);
    auto binary_tree = MyBinaryTree<NodeTest>();
    binary_tree.Add(&tree_node_1);

    return 0;
}
