#include <stdio.h>
double sqrt(long num)
{
    double l, r, delta;
    l = 0;
    r = num;
    delta = 1e-6;
    double mid, ans, diff;
    while (1) {
        mid = ((double)(l + r)) / 2;
        ans = mid * mid;
        // 绝对值
        diff = ans - num > 0 ? ans - num : num - ans;
        // 判断精度
        if (diff < delta)
            return mid;
        // 二分
        if (ans > num)
            r = mid;
        else if (ans < num)
            l = mid;
        else
            return mid;
    }
}

int main()
{
    for (int i = 1; i < 100; ++i)
        printf("sqrt %d, ans: %lf\n", i, sqrt(i));
    return 0;
}
