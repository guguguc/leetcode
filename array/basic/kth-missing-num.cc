#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int findKthPositive(vector<int>& arr, int k) {
        bool aux[1005];
        for (auto& a : aux) a = false;
        for (auto& a : arr) aux[a] = true;
        int cnt = 0, len = arr[arr.size()-1];
        int i;
        for (i = 1; i < len; ++i) {
            if (!aux[i]) ++cnt;
            if (cnt == k) break;
        }
        return i + (k-cnt);
    }

    // accumulate the internal of two subsequent number in arr as missing
    // the internal is the count of missing integer between two subsequent num
    // if missing >= k return the last number prev + (missing-k)
    // accumulate missing is equal minus missing from k
    static int findKthPositive2(vector<int>& arr, int k) {
        int prev, missing;
        prev = 0;
        for (int& n : arr) {
            missing = n - prev - 1;
            if (missing) {
                if (missing >= k) break;
                else k -= missing;
            }
            prev = n;
        }
        return prev + k;
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << Solution::findKthPositive2(v, 2);
    return 0;
}
