#include "tree.h"
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:

    static bool isSymmetic(TreeNode *root)
    {
        if (!root) return true;
        typedef std::pair<TreeNode*, TreeNode*> pp;
        stack<pp> s;
        s.push({root->left, root->right});
        while (!s.empty()) {
            auto [p1, p2] = s.top();
            s.pop();
            if (!p1 && !p2) continue;
            if ((!p1 || !p2) || p1->val != p2->val) return false;
            s.push({p1->right, p2->left});
            s.push({p1->left, p2->right});
        }
        return true;
    }

    static bool isSymmetic(const vector<int> &v)
    {
        TreeNode *root = TreeNode::buildTree(v);
        TreeNode::travalByPreorder(root);
        std::cout << "\n";
        return isSymmetic(root);
    }
};

int main()
{
    vector<int> vec1{1, 2, 2, 3, 4, 4, 3};
    vector<int> vec2{1, 2, 2, -1, 3, -1, 3};
    std::cout << Solution::isSymmetic(vec1) << "\n";
    std::cout << Solution::isSymmetic(vec2) << "\n";
    return 0;
}
