#include "tree.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // travel by preorder
    // trace parent node of non-leaf node
    // construt path by memo when encountering leaf node
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

    // divide and conquer method
    // 1. get left  subtree's path
    // 2. get right subtree's path
    // 3. merge 1 and 2
    // 4. add root val to 3's path
    vector<string> binaryTreePath2(TreeNode *root)
    {
        if (!root) return {};
        if (!root->left && !root->right) return {to_string(root->val)};
        auto paths = binaryTreePath2(root->left);
        auto rpaths = binaryTreePath2(root->right);
        paths.insert(
                paths.begin(),
                make_move_iterator(rpaths.begin()),
                make_move_iterator(rpaths.end()));
        for (auto& path : paths) path.insert(0, to_string(root->val) + "->");
        return paths;
    }
};

int main()
{
    TreeNode *root = TreeNode::buildTree({1, 2, 3, 4, 5, 6, 7});
    Solution so;
    auto ans = so.binaryTreePath2(root);
    for (auto item : ans) cout << item << "\n";
    return 0;
}
