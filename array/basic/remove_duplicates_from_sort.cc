#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, length = nums.size();
        while (j < length) {
            if (nums[j] != nums[i])
                nums[++i] = nums[j];
            j++;
        }
        return length == 0 ? 0 : i + 1;
    }
};

int main()
{
    vector<int> v({0, 0, 1, 2, 2, 2, 3, 4});
    // vector<int> v({1, 1, 3});
    // vector<int> v({0});
    // vector<int> v;
    int i = Solution().removeDuplicates(v);
    cout << i << endl;
    for (auto &n: v) cout << n << " ";
    return 0;
}
