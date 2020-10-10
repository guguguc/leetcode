#include <vector>

using namespace std;

class Solution {
public:
    // pointer i points to start
    // pointer j points to end
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans(A.size());
        int i, j, k;
        i = 0, j = A.size() - 1, k = 0;
        while (i < j) {
            if (A[k] % 2)
                ans[j--] = A[k++];
            else
                ans[i++] = A[k++];
        }
        return ans;
    }
};
