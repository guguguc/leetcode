#include <string>
#include <iostream>

using namespace std;

char memo[255][255];


string find_longest_substr(const string &s)
{
        int len = s.length();
        
        for (int i = 0; i < len; ++i) {
            memo[i][i] = 1;
            if (i > 0 && s[i] == s[i-1]) {
                memo[i-1][i] = 1;
                memo[i][i-1] = 1;
            }
        }
        
        int st = 0, ed = 0;
        for (int i = 2; i < len; ++i) {
            for (int j = 0; j + i < len; j++) {
                if (s[j] == s[j+i]) {
                    memo[j][j+i] = memo[j+1][j+i-1];
                    if (memo[j][j+i] == 1) {
                        st = j;
                        ed = j+i+1;
                    }
                }
            }
        }
        return string(s.begin() + st, s.begin() + ed);
}


int main()
{
    cout << find_longest_substr("abcdabccbaefaaaaaaaaaa");
    return 0;
}