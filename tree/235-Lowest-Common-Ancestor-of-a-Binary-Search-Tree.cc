#include "tree.h"
#include <cassert>

class Solution {
public:
    // case 1 *p and *q are more than *root, or vice verse.
    // case 1 *p is more than *root, and *q is less than *root.
    static TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int vmin = std::min(p->val, q->val), vmax = std::max(p->val, q->val);
        if (!root || p == root || q == root
            || root->val > vmin && root->val < vmax) return root;
        return root->val > vmax ? lowestCommonAncestor(root->left, p, q)
                                : lowestCommonAncestor(root->right, p, q);
    }

    static TreeNode* lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int vmin = std::min(p->val, q->val), vmax = std::max(p->val, q->val);
        while (root) {
            if (root->val > vmax) root = root->left;
            else if (root->val < vmin) root = root->right;
            else return root;
        }
    }
};

int main()
{
    TreeNode *root = TreeNode::buildTree({6,2,8,0,4,7,9,-1,-1,3,5});
    TreeNode *p, *q;
    p = root->left; q = p->right;

    assert(Solution::lowestCommonAncestor(root, p, q) == p);

    return 0;
}
