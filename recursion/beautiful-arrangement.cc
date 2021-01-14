#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int countArrangement(int n)
    {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = i + 1;
        return count(arr, 0, n);
    }

    static int count(int *arr, int l, int r)
    {
        if (l >= r)
            return 1;

        int ans = 0;
        for (int i = l; i < r; ++i) {
            if (arr[i] % (l + 1) != 0 && (l + 1) % arr[i] != 0)
                continue;
            int tmp = arr[l];
            arr[l]  = arr[i];
            arr[i]  = tmp;
            ans += count(arr, l + 1, r);
            tmp    = arr[l];
            arr[l] = arr[i];
            arr[i] = tmp;
        }
        return ans;
    }
};

int main()
{
    cout << Solution::countArrangement(15);
    return 0;
}
