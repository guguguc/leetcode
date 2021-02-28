#include "tree.h"
#include <climits>

class Solution {
public:
    int ans;
    int prev;
    int getMinimumDifference(TreeNode *root) {
        ans = INT_MAX;
        prev = -1;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode *root) {
        if (!root) return;
        dfs(root->left);
        if (prev != -1)
            ans = std::min(ans, root->val - prev);
        prev = root->val;
        std::cout << prev << " ";
        dfs(root->right);
    }
};

int main()
{
    TreeNode *tree = TreeNode::buildTree({1, -1, 3, -1, -1, 2});
    Solution s;
    std::cout << s.getMinimumDifference(tree);
    return 0;
}
