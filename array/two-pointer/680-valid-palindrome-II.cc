#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        bool ans = true;
        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
            }
            l++;
            r--;
        }
        return ans;
    }

    bool isPalindrome(const string& s, int start, int end)
    {
        int l, r;
        l = start; r = end;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++; r--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s1("ebcbbececabbacecbbcbe");
    cout << s.validPalindrome(s1) << "\n";
    return 0;
}
