#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int ret = 0;
    int length = nums.size();
    for (int i = 0; i < length; ++i) {
        int ans = 0;
        while (i < length && nums[i++] == 1) ++ans;
        ret = ans > ret ? ans : ret;
        i -= 1;
    }
    return ret;
  }
};