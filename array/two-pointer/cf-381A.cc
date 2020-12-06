#include <iostream>

using namespace std;

int a[1005];

int main()
{
    int n, i, j, a1, a2;
    a1 = a2 = 0;

    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> a[i];

    bool flag = true;
    int *t;
    for (i = 0, j = n - 1; i <= j;) {
        t = flag ? &a1 : &a2;
        if (a[i] > a[j])
            *t += a[i++];
        else
            *t += a[j--];
        flag = !flag;
    }
    cout << a1 << " " << a2;

    return 0;
}
