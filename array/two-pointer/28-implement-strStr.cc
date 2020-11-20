/**
 * Implement strstr.
 * const char* strstr(const char* haystack, const char* needle)
 * Return the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 * Note: If needle is an empty string, return 0.
 */

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int strStr(string haystack, string needle)
{
    if (needle.empty()) return 0;
    int l1, l2, i, j;
    l1 = haystack.size();
    l2 = needle.size();
    for(i = 0; i + l2 <= l1; ++i) {
        for (j = i; j < i + l2 && haystack[j] == needle[j-i]; ++j)
            ;
        if (j == i + l2)
            return j - l2;
    }
    return -1;
}

int main()
{
    assert(strStr("aaa", "a") == 0);
    assert(strStr("aaa", "") == 0);
    assert(strStr("abcde", "fgh") == -1);
    assert(strStr("abcbc", "bc") == 1);

    return 0;
}
