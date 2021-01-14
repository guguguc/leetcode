#include <fmt/core.h>
#include <string>
using namespace std;

void swap_s(string& str, int lidx, int ridx)
{
    char c = str[lidx];
    str[lidx] = str[ridx];
    str[ridx] = c;
}

void gen_perm(string s, string root="")
{
    if (s.length()==1) {
        fmt::print("{}\n", s);
        return;
    }
    int len = s.length();
    string s1;
    for (int i = 0; i < len; ++i) {
        // to add missing str part
        if (!root.empty() && i)
            fmt::print("{}", root);
        s1 = s;
        swap_s(s1, 0, i);
        fmt::print("{}", s1[0]);
        s1.erase(0, 1);
        gen_perm(s1, root+s[i]);
    }
}


int main()
{
    gen_perm("abcd");
    return 0;
}
