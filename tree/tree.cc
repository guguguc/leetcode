#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cassert>

#include "tree.hpp"


bool checkValidation(std::string s1, std::string s2)
{
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2 ? true : false;
}

/*
 * Pre order sequence: ABDFCEGH
 * In  order sequence: BFDAGEHC
 * 1. find the root node, A
 * 2. partition tree to two subtrees(left tree and right tree)
 * 3. apply recursive method to two subtrees
 */
TreeNode* createRootByPreInSeq(const std::string &pre,
                               const std::string &in)
{
    // if(!checkValidation(pre, in))
    //     throw std::invalid_argument(pre + "!=" + in);
    assert( pre.length() == in.length() );
    if (pre.empty())
        return nullptr;
    if (pre.length() == 1)
        return new TreeNode(pre[0]);

    char root_val = pre[0];
    TreeNode *p = new TreeNode(root_val);

    int idx_in  = std::find(in.begin(), in.end(), root_val) - in.begin();
    std::string pre_left  = pre.substr(1, idx_in);
    std::string pre_right = pre.substr(idx_in+1, pre.length()-idx_in-1);
    std::string in_left   = in.substr(0, idx_in);
    std::string in_right  = in.substr(idx_in+1, in.length()-idx_in-1);
    p->left  = createRootByPreInSeq(pre_left, in_left);
    p->right = createRootByPreInSeq(pre_right, in_right);

    return p;
}

void BinaryTree::createByPreInSeq(const std::string &pre,
                                  const std::string &in)
{
    if (!checkValidation(pre, in))
        throw std::invalid_argument(pre + "!=" + in);
    this->root = createRootByPreInSeq(pre, in);
}
void BinaryTree::createByInPostSeq(const std::string &in,
                                   const std::string &post)
{

}

void travalByPreOrder(const TreeNode *root)
{
    if (root) {
        std::cout << root->val << " ";
        travalByPreOrder(root->left);
        travalByPreOrder(root->right);
    }
}

void travalByInOrder(const TreeNode *root)
{
    if (root) {
        travalByInOrder(root->left);
        std::cout << root->val << " ";
        travalByInOrder(root->right);
    }
}

void travalByPostOrder(const TreeNode *root)
{
    if (root) {
        travalByPostOrder(root->left);
        travalByPostOrder(root->right);
        std::cout << root->val << " ";
    }
}
