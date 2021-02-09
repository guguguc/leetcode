#include "tree.h"
#include <iosfwd>
#include <string>

template <typename T>
std::pair<bool, int> _isAVL(TreeNode<T> *root)
{
    if (root == nullptr)
        return std::make_pair(true, 0);

    int lh, rh;
    auto pl = _isAVL(root->left);
    auto ph = _isAVL(root->right);
    lh = pl.second, rh = ph.second;

    bool flag = false;
    if (pl.first && ph.first && std::abs(lh - rh) <= 1)
        flag = true;

    return std::make_pair(flag, std::max(lh, rh) + 1);
}

template <typename T>
inline bool isAVL(BinaryTree<T> &tree)
{
    return _isAVL(tree.getRoot()).first;
}

template <typename T>
void travalByPreOrder(const TreeNode<T> *root, std::ostream &out)
{
    if (root) {
        out << root->val << " ";
        travalByPreOrder(root->left, out);
        travalByPreOrder(root->right, out);
    }
}

template <typename T>
void travalByInOrder(const TreeNode<T> *root, std::ostream &out)
{
    if (root) {
        travalByInOrder(root->left, out);
        out << root->val << " ";
        travalByInOrder(root->right, out);
    }
}

template <typename T>
void travalByPostOrder(const TreeNode<T> *root, std::ostream &out)
{
    if (root) {
        travalByPostOrder(root->left, out);
        travalByPostOrder(root->right, out);
        out << root->val << " ";
    }
}

// TreeNode<char> *createRootByPreInSeq(const std::string &pre,
//                                      const std::string &in)
//
// {
//     if (pre.empty())
//         return nullptr;
//
//     char root_val = pre[0];
//     auto *p    = new TreeNode<char>(root_val);
//
//     int idx_in = std::find(in.begin(), in.end(), root_val) - in.begin();
//     std::string pre_left  = pre.substr(1, idx_in);
//     std::string pre_right = pre.substr(idx_in + 1, pre.length() - idx_in -
//     1); std::string in_left   = in.substr(0, idx_in); std::string in_right  =
//     in.substr(idx_in + 1, in.length() - idx_in - 1);
//
//     p->left  = createRootByPreInSeq(pre_left, in_left);
//     p->right = createRootByPreInSeq(pre_right, in_right);
//
//     return p;
// }
//
