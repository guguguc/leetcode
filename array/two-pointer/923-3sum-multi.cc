#include <algorithm>
#include <fmt/core.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int threeSumMulti_1(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int len       = arr.size();
        long long cnt = 0;
        for (int i = 0; i < len; ++i) {
            int l = i + 1, r = len - 1;
            while (l < r) {
                if (arr[l] + arr[r] < target - arr[i])
                    l++;
                else if (arr[l] + arr[r] > target - arr[i])
                    r--;
                else if (arr[l] != arr[r]) {
                    int k1, k2;
                    k1 = k2 = 1;
                    while (l < r && arr[l] == arr[l + 1]) { k1++; l++; }
                    while (l < r && arr[r] == arr[r - 1]) { k2++; r--; }
                    l++; r--;
                    cnt += k1 * k2;
                }
                else {
                    cnt += (r - l + 1) * (r - l) / 2;
                    break;
                }
            }
        }
        return cnt % int(1e9 + 7);
    }

    // find the count of i, j, k that meets i < j < k
    // and arr[i] + arr[j] + arr[k] = target.
    // 0 <= arr[i] <= 100; arr.length <= 3000; 0 <= target <= 300
    // case 1: arr[i] = arr[j] = arr[k] -> C(n, 3)
    // case 2: arr[i] = arr[j] && arr[j] != arr[k] -> C(n, 2) * count(arr[k])
    // case 3: arr[i] != arr[j] != arr[k] -> count(arr[i]) * count(arr[j]) *
    // count(arr[k]) 1 2 3 4 5
    // 8
    static int threeSumMulti_2(vector<int> &arr, int target)
    {
        long ans = 0;
        unordered_map<int, long> table;
        for (auto &item : arr) table[item]++;

        for (auto &[i, cnti] : table)
            for (auto &[j, cntj] : table) {
                int k = target - (i + j);
                if (!table.count(k))
                    continue;
                int cntk = table[k];
                if (i == j && j == k)
                    ans += cnti * (cnti - 1) * (cnti - 2) / 6;
                else if (i == j && j != k)
                    ans += cnti * (cnti - 1) / 2 * cntk;
                else if (i < j && j < k)
                    ans += cnti * cntj * cntk;
            }
        return ans % (int(1e9 + 7));
    }
};

int main()
{
    vector<int> v1{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    cout << Solution::threeSumMulti_1(v1, 8);
    return 0;
}
