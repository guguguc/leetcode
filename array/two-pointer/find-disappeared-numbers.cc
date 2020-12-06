#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 * some elements appear twice and others appear once.
 * Find all the elements of [1, n] inclusive that do not appear in this
 * array. Could you do it without extra space and in O(n) runtime?
 * You may assume the returned list does not count as extra space.
 */

vector<int> findDisappearedNumbers_1(vector<int> &nums)
{
    vector<int> ans;
    int length = nums.size() + 1;
    vector<bool> aux(length);
    for (int &n : nums)
        aux[n] = true;
    for (int i = 1; i < length; ++i)
        if (!aux[i])
            ans.push_back(i);
    return ans;
}

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int length = nums.size() + 1;
    vector<int> ans(length);
    int i, j;
    for (i = 1; i < length; ++i)
        ans[i] = i;
    for (int &n : nums)
        ans[n] -= n;
    for (i = 1, j = 0; i < length; ++i)
        if (ans[i] == i)
            ans[j++] = i;
    ans.resize(j);
    return ans;
}

int main()
{
    vector<int> v1{1, 2, 2};
    vector<int> v2{1, 1, 1};
    vector<int> v3{4, 3, 2, 7, 8, 2, 3, 1};

    auto func = findDisappearedNumbers;
    assert(func(v1) == (vector<int>{3}));
    assert(func(v2) == (vector<int>{2, 3}));
    assert(func(v3) == (vector<int>{5, 6}));

    return 0;
}
