#include <stdio.h>
#include <assert.h>

#define PI 3.141592
#define MAGIC 0.28125

// arctan(x) 近似为 (x / (1 + 0.28125x^2)) -1 < x < 1
// arctan(x) + arctan(1 / x) = {  pi / 2, x > 0
//                               -pi / 2, x < 0}
// }

double sqrt(long num)
{
    double l, r, delta;
    l = 0, r = num;
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

// 返回(- pi / 2, pi / 2)间的角度值
double arctan(double x)
{
    double abs_x = x > 0 ? x : -x;
    double tx = abs_x > 1 ? (1 / x) : x;
    double ty = tx / (1 + MAGIC * tx * tx);
    // abx_x大于1
    if (abs_x > 1) {
        // 判断x是否大于0
        double delta = x > 0 ? (PI / 2) : (- PI / 2);
        ty = delta - ty;
    }
    return ty;
}

double get_angle(double x, double y)
{
    // x = 0 y = 0 错误输入
    // x > 0 角度为1, 4象限(-pi / 2, pi / 2) --> arctan(x)
    // x < 0 y > 0 角度为第2象限 --> pi + arctan(x)
    // x < 0 y < 0 角度为第3象限 --> -pi + arctan(x)
    // x = 0 y > 0 pi / 2
    // x = 0 y < 0 -pi / 2
    assert(x != 0 && y != 0);
    if (x == 0)
        return y > 0 ? PI / 2 : -PI / 2;
    double angle = arctan(y / x);
    if (x > 0)
        return angle;
    else 
        return y > 0 ? (PI + angle) : (-PI + angle);
}

// [-pi, pi]
void transform(double x, double y)
{
    double length = sqrt(x * x + y * y);
    double angle = get_angle(x, y);
    printf("length: %lf, angle: %lf\n", length, angle);
}

int main()
{
    transform(1, 1);
    transform(1, sqrt(3));
    transform(-1, sqrt(3));
    transform(sqrt(3), -1);

    // 结果
    // length: 1.414214, angle: 0.780488
    // length: 1.732051, angle: 1.042933
    // length: 1.732051, angle: 2.098659
    // length: 1.732051, angle: -0.527863

    return 0;
}