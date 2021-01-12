#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};

        vector<vector<int>> ans;
        int i, j, k, m, n, length;
        length  = nums.size();
        vector<pair<int, int>> tmp(length * (length-1)/2);
        sort(nums.begin(), nums.end());

        k = 0;
        for (i = 0; i < length; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (j = i + 1; j < length; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (i && nums[i] == nums[i-1]) continue;
                tmp[k++] = {i, j};
                cout << "(" << i << " " << j << ")\n";
        }
        cout << k << "\n";
        tmp.resize(k);

        for(const auto& [i1, i2] : tmp) {
            n = nums[i1] + nums[i2];
            i = i2+1; j = length - 1;
            while (i < j) {
                m = nums[i] + nums[j];
                if (m + n < target) ++i;
                else if (m + n > target) --j;
                else {
                    ans.push_back({nums[i1], nums[i2], nums[i], nums[j]});
                    i++; j--;
                    while (i < j && nums[i] == nums[i-1]) i++;
                    while (i < j && j + 1 < length && nums[j] == nums[j+1]) j--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v(4, 0);
    auto ans = s.fourSum(v, 0);
    for (const auto& vec : ans) {
        for_each(vec.begin(), vec.end(), [](int item) {cout << item << " ";} );
        cout << "\n";
    }
    return 0;
}
