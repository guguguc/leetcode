#include "tree.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<string> path;
    vector<string> binaryTreePath(TreeNode *root)
    {
        parent[root] = root;
        dfs(root);
        return path;
    }
    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        if (!root->right && !root->left) {
            string route;
            for (auto node = root;; node=parent[node]) {
                if (node != root) route += ">-";
                auto sval = to_string(node->val);
                route += string(sval.rbegin(), sval.rend());
                if (parent[node] == node) break;
            }
            reverse(route.begin(), route.end());
            path.push_back(route);
        }
        dfs(root->left);
        dfs(root->right);
    }
};

int main()
{
    TreeNode *root = TreeNode::buildTree({1, 2, 3, 4, 5, 6, 7});
    Solution so;
    auto ans = so.binaryTreePath(root);
    for (auto item : ans) cout << item << "\n";
    return 0;
}