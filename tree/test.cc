#include "tree.h"
#include <iostream>

using namespace std;

int main()
{
    const string pre_order_seq = "ABDFCEGH";
    const string in_order_seq  = "BFDAGEHC";

    BinaryTree tree = BinaryTree();
    tree.createByPreInSeq(pre_order_seq, in_order_seq);

    travalByPreOrder(tree.root);
    cout << endl;
    travalByInOrder(tree.root);
    cout << endl;
    travalByPostOrder(tree.root);
    cout << endl;

    return 0;
}
