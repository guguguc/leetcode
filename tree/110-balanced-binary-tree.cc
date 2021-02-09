#include "tree.h"

using namespace std;

class Solution {
    typedef pair<bool, int> pp;
public:
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }

    pp helper(TreeNode *root)
    {
        if (!root) return {true, 0};
        auto [f1, h1] = helper(root->left);
        auto [f2, h2] = helper(root->right);
        return {f1 && f2 && (abs(h1-h2) <= 1), max(h1, h2)+1};
    }
};
