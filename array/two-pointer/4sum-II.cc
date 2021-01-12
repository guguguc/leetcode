#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    static int fourSumCount1(vector<int> &A, vector<int> &B, vector<int> &C,
                             vector<int> &D)
    {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        int len = A.size() * A.size();
        vector<int> v1(len), v2(len);
        merge(A, B, v1);
        merge(C, D, v2);
        mysort(v1, A.size());
        mysort(v2, A.size());
        int cnt = twoSumCount(v1, v2, 0);
        return cnt;
    }

    static void merge(const vector<int> &v1, const vector<int> &v2,
                      vector<int> &v3)
    {
        int len = v1.size(), k = 0;
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                v3[k++] = v1[i] + v2[j];
    }

    static void mysort(vector<int> &v, int n)
    {
        vector<int> idx(n);
        vector<int> aux(v.size());
        set<int> st;
        int k, len;
        k   = 0;
        len = v.size();
        for (int i = 0; i < n; ++i) {
            idx[i] = i * n;
            st.insert(i);
        }
        while (k < len) {
            int min      = INT_MAX;
            auto min_idx = st.begin();
            for (auto it = st.begin(); it != st.end(); ++it) {
                if (v[idx[*it]] < min) {
                    min     = v[idx[*it]];
                    min_idx = it;
                }
            }
            aux[k++] = min;
            idx[*min_idx]++;
            if (idx[*min_idx] >= (*min_idx + 1) * n)
                st.erase(*min_idx);
        }
        for (int i = 0; i < n * n; ++i)
            v[i] = aux[i];
    }

    static int twoSumCount(vector<int> &v1, vector<int> &v2, int target)
    {
        int i, j, k, len, cnt;
        i = k = cnt = 0;
        len = v1.size();
        j = len - 1;
        while (k < 2 * len) {
            int n1 = v1[i] + v2[j];
            if (n1 > target)
                j--;
            else if (n1 < target)
                i++;
            else {
                int k1, k2;
                k1 = k2 = 1;
                i++;
                j--;
                k++;
                while (i < len && v1[i] == v1[i - 1])
                    k1++, i++, k++;
                while (j >= 0 && v2[j] == v2[j + 1])
                    k2++, j--, k++;
                cnt += k1 * k2;
            }
            k++;
        }
        return cnt;
    }

    static int fourSumCount2(vector<int> &A, vector<int> &B, vector<int> &C,
                             vector<int> &D)
    {
        int cnt = 0, length = A.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++)
                for (int k = 0; k < length; ++k)
                    for (int l = 0; l < length; ++l)
                        if (A[i] + B[j] + C[k] + D[l] == 0)
                            cnt++;
        return cnt;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> v(4, vector<int>(n));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    cout << Solution::fourSumCount1(v[0], v[1], v[2], v[3]) << "\n";
    cout << Solution::fourSumCount2(v[0], v[1], v[2], v[3]);
    return 0;
}
