#ifndef __Tree__
#define __Tree__

#include <iostream>
#include <vector>

class TreeNode {
    typedef int NODE_TYPE;

public:
    static TreeNode* buildTree(std::initializer_list<int> list, int start=0)
    {
        if (list.size() <= start || *(list.begin() + start) == -1) return nullptr;
        TreeNode *root = new TreeNode(*(list.begin() + start));
        root->left = buildTree(list, 2 * start + 1);
        root->right = buildTree(list, 2 * start + 2);
        return root;
    }

    static void travalByPreorder(const TreeNode *root)
    {
        if (!root) return;
        std::cout << root->val << " \n";
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
