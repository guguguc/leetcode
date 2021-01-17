class TreeNode {
    typedef int NODE_TYPE;
public:
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(NODE_TYPE val): val(val), left(nullptr), right(nullptr) {}
    NODE_TYPE val;
    TreeNode *left;
    TreeNode *right;
};
