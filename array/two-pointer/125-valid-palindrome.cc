#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static bool isPalindrome(string s)
    {
        string aux;
        for (auto& c : s) if (isalnum(c)) aux += convert(c);
        int l = 0, r = aux.length() - 1;
        while (l < r) {
            if (aux[l] != aux[r])
                return false;
            l++; r--;
        }
        return true;
    }

    static char convert(char c)
    {
        return isalpha(c) ? tolower(c) : c;
    }
};

int main()
{
    string s1("A man, a plan, a canal: Panama");
    string s2("race a car");
    cout << Solution::isPalindrome(s1) << "\n";
    cout << Solution::isPalindrome(s2);
    return 0;
}
