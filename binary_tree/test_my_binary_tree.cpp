#include "my_binary_tree.h"
#include <string>

using namespace std;

class NodeTest
{
public:
    NodeTest(int elem1, string elem2);
    ~NodeTest();
protected:
private:
    int elem_a;
    string elem_b;
};

NodeTest::NodeTest(int elem_int, string elem_string)
{
    this->elem_a = elem_int;
    this->elem_b = elem_string;
}

NodeTest::~NodeTest()
{

}

int main()
{
    auto node1 = NodeTest(1, "node1");
    auto node2 = NodeTest(2, "node2");

    auto tree_node = MyBinaryTreeNode<NodeTest>(node1);

    return 0;
}
