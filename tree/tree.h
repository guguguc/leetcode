#ifndef _TREE_H
#define _TREE_H

#include <vector>

template <typename T> class TreeNode {
public:
    using value_type = T;
    TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
    ~TreeNode() = default;

public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template <typename T> class BinaryTree {
public:
    using value_type = T;
    BinaryTree() : root(nullptr) {}
    BinaryTree(const std::vector<T> &vec);
    void insert(T val);
    size_t count(T val) const;
    void erase(T val);
    void clear();
    TreeNode<T>* getRoot() const { return root; }
    size_t size() const { return getSize(root); }
    size_t height() const { return getHeight(root); };
    size_t leafs() const { return getLeafNum(this->root); }
    bool empty();
    ~BinaryTree() { destroyRecursive(root); };

private:
    size_t getSize(TreeNode<T> *root) const;
    size_t getHeight(TreeNode<T> *root) const;

    size_t getLeafNum(TreeNode<T> *root) const;
    void destroyRecursive(TreeNode<T> *root);

private:
    TreeNode<T> *root;
};

template <typename T> BinaryTree<T>::BinaryTree(const std::vector<T> &vec)
{
    root = nullptr;
    for (const auto &v : vec)
        this->insert(v);
}

template<typename T>
void BinaryTree<T>::insert(T val)
{
    TreeNode<T> **p = &root;
    while (*p) {
        p = val >= (*p)->val ? &((*p)->left) : &((*p)->right);
    }
    *p = new TreeNode<T>(val);
}

template<typename T>
size_t BinaryTree<T>::count(T val) const
{
    auto p = root;
    size_t cnt = 0;
    while (p) {
        if (val > p->val)
            p = p->left;
        else if (val < p->val)
            p = p->right;
        else
            p = p->left, ++cnt;
    }
    return cnt;
}

// template <typename T>
// TreeNode<T> *BinaryTree<T>::erase(T val)
// {
//     if (node == nullptr)
//         return nullptr;
// 
//     auto p = node;
//     if (val > node->val) {
//         node->left = erase(val, node->left);
//     }
//     else if (val < node->val) {
//         node->right = erase(val, node->right);
//     }
//     else {
//         if (node->left) {
//             node->left->right = node->right;
//             p                 = node->left;
//         }
//         else if (node->right) {
//             p = node->right;
//         }
//         else {
//             p = nullptr;
//         }
//         delete node;
//     }
//     return p;
// }
template<typename T> void BinaryTree<T>::erase(T val)
{
    auto p = root;
}

template <typename T> void BinaryTree<T>::clear()
{
    destroyRecursive(root);
    root = nullptr;
}

template <typename T> size_t BinaryTree<T>::getSize(TreeNode<T> *root) const
{
    return root ? getSize(root->left) + getSize(root->right) + 1 : 0;
}

template <typename T> size_t BinaryTree<T>::getHeight(TreeNode<T> *root) const
{
    return root ? std::max(getHeight(root->left), getHeight(root->right)) + 1
                : 0;
}

template <typename T> size_t BinaryTree<T>::getLeafNum(TreeNode<T> *root) const
{
    if (root == nullptr)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return getLeafNum(root->left) + getLeafNum(root->right);
}

template <typename T> void BinaryTree<T>::destroyRecursive(TreeNode<T> *root)
{
    if (root == nullptr)
        return;
    if (root->left)
        destroyRecursive(root->left);
    if (root->right)
        destroyRecursive(root->right);
    delete root;
}

#endif