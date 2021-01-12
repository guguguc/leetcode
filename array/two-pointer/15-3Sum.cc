#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int i, j, k, n;
        for (i = 0; i < length; ++i) {
            for (j = i + 1, k = length - 1; j < k;) {
                n = nums[j] + nums[k];
                if (n > -nums[i])
                    --k;
                else if (n < -nums[i])
                    ++j;
                else {
                    ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++; k--;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && k + 1 < length && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return ans;
    }

};

