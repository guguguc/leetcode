#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mp;

        int len = arr.size();
        for (int i = 0; i < len; ++i)
            mp[arr[i]] = i;

        len = pieces.size();
        for (int i = 0; i < len; ++i) {
            if (!mp.count(pieces[i][0])) return false;
            int idx = mp[pieces[i][0]] - 1;
            for (auto& item : pieces[i]) {
                if (mp[item] != idx+1) return false;
                idx = mp[item];
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr{19};
    vector<vector<int>> pieces{{18}};
    cout << Solution::canFormArray(arr, pieces);
    return 0;
}
