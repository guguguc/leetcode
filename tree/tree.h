#include <string>
#include <vector>

class BinaryTree {
public:
    class TreeNode;
    using Type = int;

public:
    BinaryTree() : size_(-1), height_(-1), root(nullptr) {}
    BinaryTree(const std::vector<Type> &vec);
    void insert(Type val) { root = insert(val, root); };
    void erase(Type val) { root = erase(val, root); };
    void clear();
    size_t size() const;
    size_t height() const;
    bool empty();
    void buildByPreInSeq(const std::string &pre, const std::string &in);
    void buildByInPostSeq(const std::string &in, const std::string &post);
    ~BinaryTree();

private:
    TreeNode *insert(Type val, TreeNode *node);
    TreeNode *erase(Type val, TreeNode *node);
    size_t getSize(TreeNode *root) const;
    size_t getHeight(TreeNode *root) const;
    void destroyRecursive(TreeNode *root);

public:
    size_t size_;
    size_t height_;
    TreeNode *root;
};

class BinaryTree::TreeNode {
public:
    using Type = BinaryTree::Type;
    TreeNode(Type val) : val(val), left(nullptr), right(nullptr) {}
    ~TreeNode() = default;

public:
    Type val;
    TreeNode *left;
    TreeNode *right;
};

void travalByPreOrder(const BinaryTree::TreeNode *root);
void travalByInOrder(const BinaryTree::TreeNode *root);
void travalByPostOrder(const BinaryTree::TreeNode *root);

BinaryTree::TreeNode *createRootByPreInSeq(const std::string &pre,
                                           const std::string &in);

bool checkValidation(const std::string s1, const std::string s2);
bool isAVL(BinaryTree &tree);
std::pair<bool, int> isAVL_(BinaryTree::TreeNode *root);
