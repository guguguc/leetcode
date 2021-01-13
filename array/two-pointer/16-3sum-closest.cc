#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = INT_MAX;
        int i, j, k, m, n, length;
        length = nums.size();
        sort(nums.begin(), nums.end());
        for (i = 0; i < length; ++i) {
            j = i + 1;
            k = length - 1;
            m = nums[i];
            while (j < k) {
                n = nums[j] + nums[k];
                if (m + n > target)
                    k--;
                else if (m + n < target)
                    j++;
                else
                    return m + n;
                ans = abs(target - ans) > abs(target - (m + n)) ? (m + n) : ans;
            }
        }
        return ans;
    }
};
