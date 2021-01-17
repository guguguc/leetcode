#include <bits/stdc++.h>
#include <fmt/core.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int len;
    void fpermute(vector<int> &nums, int cur)
    {
        if (cur >= len) {
            ans.push_back(nums);
            return;
        }
        vector<bool> st(25, false);
        for (int i = cur; i < len; ++i) {
            if (!st[nums[i]+10]) {
                st[nums[i]+10] = true;
                std::swap(nums[i], nums[cur]);
                fpermute(nums, cur + 1);
                //std::swap(nums[i], nums[cur]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        len = nums.size();
        fpermute(nums, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums{2, 2, 1, 1};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    fmt::print("size :{}\n", ans.size());
    for_each(ans.begin(), ans.end(), [](vector<int> &item) {
        for_each(item.begin(), item.end(), [](int n) { fmt::print("{} ", n); });
        fmt::print("\n");
    });
    return 0;
}
