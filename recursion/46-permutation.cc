#include <bits/stdc++.h>
#include <fmt/core.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int len;
    void fpermute(vector<int>& nums, int cur)
    {
        if (cur >= len)
            ans.push_back(nums);

        for (int i = cur; i < len; ++i) {
            std::swap(nums[i], nums[cur]);
            fpermute(nums, cur + 1);
            std::swap(nums[i], nums[cur]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (!ans.empty()) ans.clear();
        len = nums.size();
        fpermute(nums, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
    for_each(ans.begin(), ans.end(), [](vector<int> &item) {
        for_each(item.begin(), item.end(), [](int n) { fmt::print("{} ", n); });
        fmt::print("\n");
    });
    return 0;
}
