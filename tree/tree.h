#ifndef __Tree__
#define __Tree__

#include <iostream>
#include <vector>

class TreeNode {
    typedef int NODE_TYPE;

public:
    static TreeNode* buildTree(const std::vector<int> &vec, int start=0)
    {
        if (vec.size() <= start || vec[start] == -1) return nullptr;
        TreeNode *root = new TreeNode(vec[start]);
        root->left = buildTree(vec, 2 * start + 1);
        root->right = buildTree(vec, 2 * start + 2);
        return root;
    }

    static void travalByPreorder(const TreeNode *root)
    {
        if (!root) return;
        std::cout << root->val << " ";
        travalByPreorder(root->left);
        travalByPreorder(root->right);
    }

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(NODE_TYPE val): val(val), left(nullptr), right(nullptr) {}
    NODE_TYPE val;
    TreeNode *left;
    TreeNode *right;
};

#endif
