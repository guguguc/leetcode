#include <string>

class TreeNode {
    using Type = char;
public:
    TreeNode(Type val): val(val), left(nullptr), right(nullptr) {}
public:
    Type val;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTree {
public:
    BinaryTree(): height(0), root(nullptr) {}
    void createByPreInSeq(const std::string &pre, const std::string &in);
    void createByInPostSeq(const std::string &in, const std::string &post);
public:
    unsigned height;
    TreeNode *root;
};

void travalByPreOrder(const TreeNode *root);
void travalByInOrder(const TreeNode *root);
void travalByPostOrder(const TreeNode *root);

bool checkValidation(const std::string s1, const std::string s2);
TreeNode* createRootByPreInSeq(const std::string &pre, const std::string &in);
