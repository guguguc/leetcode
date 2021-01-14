#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s)
    {
        int ans, cnt, start;
        ans = cnt = start = 0;
        int len           = s.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < len; ++i) {
            if (!mp.count(s[i]) || mp[s[i]] < start) {
                mp[s[i]] = i;
                cnt++;
            }
            else if (mp[s[i]] >= start){
                ans   = ans > cnt ? ans : cnt;
                cnt = i - mp[s[i]];
                start = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
        }
        return ans > cnt ? ans : cnt;
    }

    // use slide window
    // keep a window whose length always increasing
    // scan string s, store it's item index using map
    // when find a char occur before, increasing or keep window's left boundary
    // else increasing it's right boundary
    static int lengthOfLongestSubstring2(string s)
    {
        unordered_map<char, int> mp;
        int l, r, len, ans;
        l = r = ans = 0;
        len = s.length();
        while (r < len) {
            if (mp.count(s[r]))
                l = max(l, mp[s[r]]);
            ans = max(ans, l-r+1);
            mp[s[r]] = r+1;
            r++;
        }
        return ans;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cout << Solution::lengthOfLongestSubstring(s) << "\n";
    }
    return 0;
}
