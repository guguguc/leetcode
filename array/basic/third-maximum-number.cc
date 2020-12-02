#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdint>

typedef long long ll;
using namespace std;

int firstMax(vector<int>& nums)
{
    int ans = INT32_MIN;
    for (auto &n: nums)
        ans = max(ans, n);
    return ans;
}

int secondMax(vector<int>& nums)
{
    // a1 = firstMax
    // a2 = secondMax
    ll a1, a2;
    a1 = a2 = INT64_MIN;
    for (auto &n: nums) {
        if (n <= a2 || n == a1) continue;
        a2 = n;
        if (a2 > a1) swap(a2, a1);
    }
    if (a2 == INT64_MIN) a2 = a1;
    return (int)a2;
}

/**
 * Just for test.
 */
int thirdMax_t1(vector<int>& nums)
{
    int a1, a2, a3;
    a1 = firstMax(nums);
    a2 = secondMax(nums);
    a3 = INT32_MIN;
    for (auto &n: nums) {
        if (n != a1 && n != a2)
            a3 = max(n, a3);
    }
    return a3;
}

/**
 * So ugly!
 */
int thirdMax_t2(vector<int>& nums)
{
    // a[0] = firstMax
    // a[1] = secondMax
    // a[2] = thirdMax.
    ll a[3];
    a[0] = a[1] = a[2] = INT64_MIN;
    for (auto &n: nums) {
        if (n > a[0]) {
            if (a[0] > a[1]) {
                a[2] = a[1];
                a[1] = a[0];
            }
            a[0] = n;
        }
        if (n < a[0]) {
            if (n > a[1]) {
                a[2] = a[1];
                a[1] = n;
            }
            if (n < a[1])
                a[2] = max((ll)n, a[2]);
        }
    }
    if (a[2] == INT64_MIN)
        a[2] = max(a[0], a[1]);
    return (int)a[2];
}

/**
 * Maintain an orderd set that has at most three elements.
 */
int thirdMax_t3(vector<int>& nums)
{
    int length = nums.size();
    // 1. All same nums.
    // 2. Two distinct nums.
    // 1. Greater than three distinct nums.
    set<int> s;
    for (auto& n: nums) {
        s.insert(n);
        if (s.size() > 3) s.erase(s.begin());
    }
    return s.size() == 3 ? *s.begin() : *s.end();
}

int thirdMax(vector<int>& nums)
{
    ll a[3];
    a[0] = a[1] = a[2] = INT64_MIN;
    for (int& n: nums) {
        if (n <= a[2] || n == a[1] || n == a[0]) continue;
        a[2] = n;
        if (a[2] > a[1]) swap(a[2], a[1]);
        if (a[1] > a[0]) swap(a[1], a[0]);
    }
    if (a[2] == INT64_MIN)
        a[2] = a[0];
    return (int)a[2];
}

/*
 * Given a non-empty array of integers, return the third maximum number
 * in this array. If it does not exist, return the maximum number.
 * The time complexity must be in O(n).
 */
int main(int argc, char **argv)
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{5, 4, 3, 2, 1};
    vector<int> v3{1, 2, 3, 4, 3, 2, 1};
    vector<int> v4(5, 1);
    vector<int> v5{20, 10, 13, 5, 99, 7, 108};
    vector<int> v6{1, 2, INT32_MIN};
    vector<int> v7{1, 2, 1, 2, 1, 2};
    assert(secondMax(v1) == 4);
    assert(secondMax(v2) == 4);
    assert(secondMax(v3) == 3);
    assert(secondMax(v4) == 1);
    assert(secondMax(v5) == 99);

    auto func = thirdMax_t3;
    assert(func(v1) == 3);
    assert(func(v2) == 3);
    assert(func(v3) == 2);
    assert(func(v4) == 1);
    assert(func(v5) == 20);
    assert(func(v6) == INT32_MIN);
    return 0;
}
