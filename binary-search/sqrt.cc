#include <cstdio>
#include <iostream>

#define square(x) (long long)x * x
class Solution {
public:
    static int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + (long long)r + 1) / 2;
            if (square(mid) <= x) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

int main()
{
    std::cout << Solution::mySqrt(5);
    return 0;
}
