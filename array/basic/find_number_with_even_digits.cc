#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int &num : nums) {
            if (digits(num) % 2 == 0)
                ans++;
        }
        return ans;
    }
    int digits(int num)
    {
        int digits = 1;
        while (num / 10 != 0) {
            digits++;
            num /= 10;
        }
        return digits;
    }
};