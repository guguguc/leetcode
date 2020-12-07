#include "tree.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>

/**********************************
 *           BinaryTree
 **********************************/

BinaryTree::BinaryTree(const std::vector<BinaryTree::Type> &vec)
{
    root = nullptr;
    for (const auto v : vec)
        this->insert(v);
}

BinaryTree::TreeNode *BinaryTree::insert(BinaryTree::Type val,
                                         BinaryTree::TreeNode *node)
{
    if (node == nullptr) {
        node = new TreeNode(val);
        // std::cout << "insert node " << node << std::endl;
        return node;
    }
    else {
        if (val > node->val)
            node->left = insert(val, node->left);
        else
            node->right = insert(val, node->right);
        return node;
    }
}

BinaryTree::TreeNode *BinaryTree::erase(BinaryTree::Type val,
                                        BinaryTree::TreeNode *node)
{
    if (node == nullptr)
        return nullptr;

    auto p = node;
    if (val > node->val) {
        node->left = erase(val, node->left);
    }
    else if (val < node->val) {
        node->right = erase(val, node->right);
    }
    // p only change in this case
    else {
        if (node->left) {
            node->left->right = node->right;
            p                 = node->left;
        }
        else if (node->right) {
            p = node->right;
        }
        else {
            p = nullptr;
        }
        delete node;
    }
    return p;
}

void BinaryTree::clear()
{
    destroyRecursive(root);
    root = nullptr;
}

size_t BinaryTree::size() const
{
    // if (size_ == -1)
    //     return getSize(root);
    return getSize(root);
}

size_t BinaryTree::height() const
{
    // if (height_ == -1)
    //     return height_;
    return getHeight(root);
}

size_t BinaryTree::getSize(BinaryTree::TreeNode *root) const
{
    return root ? getSize(root->left) + getSize(root->right) + 1 : 0;
}

size_t BinaryTree::getHeight(BinaryTree::TreeNode *root) const
{
    return root ? std::max(getHeight(root->left), getHeight(root->right)) + 1
                : 0;
}

void BinaryTree::destroyRecursive(BinaryTree::TreeNode *root)
{
    if (root == nullptr)
        return;
    if (root->left)
        destroyRecursive(root->left);
    if (root->right)
        destroyRecursive(root->right);
    delete root;
}

void BinaryTree::buildByPreInSeq(const std::string &pre, const std::string &in)
{
    if (!checkValidation(pre, in))
        throw std::invalid_argument(pre + "!=" + in);
    this->root = createRootByPreInSeq(pre, in);
}

void BinaryTree::buildByInPostSeq(const std::string &in,
                                  const std::string &post)
{
}

BinaryTree::~BinaryTree() { destroyRecursive(root); }

/****************************************
 *           Auxiliary function
 ***************************************/

bool isAVL(BinaryTree &tree) { return isAVL_(tree.root).first; }

std::pair<bool, int> isAVL_(BinaryTree::TreeNode *root)
{
    if (root == nullptr)
        return std::make_pair(true, 0);

    int lh, rh;
    auto pl = isAVL_(root->left);
    auto ph = isAVL_(root->right);
    lh = pl.second, rh = ph.second;

    bool flag = false;
    if (pl.first && ph.first && std::abs(lh - rh) <= 1)
        flag = true;

    return std::make_pair(flag, std::max(lh, rh) + 1);
}

/*
 * Pre order sequence: ABDFCEGH
 * In  order sequence: BFDAGEHC
 * 1. find the root node, A
 * 2. partition tree to two subtrees(left tree and right tree)
 * 3. apply recursive method to two subtrees
 */
BinaryTree::TreeNode *createRootByPreInSeq(const std::string &pre,
                                           const std::string &in)
{
    if (pre.empty())
        return nullptr;

    BinaryTree::Type root_val = pre[0];
    auto *p                   = new BinaryTree::TreeNode(root_val);

    int idx_in = std::find(in.begin(), in.end(), root_val) - in.begin();
    std::string pre_left  = pre.substr(1, idx_in);
    std::string pre_right = pre.substr(idx_in + 1, pre.length() - idx_in - 1);
    std::string in_left   = in.substr(0, idx_in);
    std::string in_right  = in.substr(idx_in + 1, in.length() - idx_in - 1);

    p->left  = createRootByPreInSeq(pre_left, in_left);
    p->right = createRootByPreInSeq(pre_right, in_right);

    return p;
}

/**
 * Check whether two strings contain the same number of characters.
 */
bool checkValidation(std::string s1, std::string s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2 ? true : false;
}

void travalByPreOrder(const BinaryTree::TreeNode *root)
{
    if (root) {
        std::cout << root->val << " ";
        travalByPreOrder(root->left);
        travalByPreOrder(root->right);
    }
}

void travalByInOrder(const BinaryTree::TreeNode *root)
{
    if (root) {
        travalByInOrder(root->left);
        std::cout << root->val << " ";
        travalByInOrder(root->right);
    }
}

void travalByPostOrder(const BinaryTree::TreeNode *root)
{
    if (root) {
        travalByPostOrder(root->left);
        travalByPostOrder(root->right);
        std::cout << root->val << " ";
    }
}
