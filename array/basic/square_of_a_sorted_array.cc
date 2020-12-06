#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int length = A.size();
        if (length == 1)
            return vector<int>(1, A[0] * A[0]);
        vector<int> B(length);
        int idx = 0;
        while (A[idx++] < 0)
            ;
        int i = idx - 1, j = idx, k = 0;
        while (i > 0 && j < length) {
            if (-A[i] < A[j]) {
                B[k++] = A[i] * A[i];
                i--;
            }
            else {
                B[k++] = A[j] * A[j];
                j++;
            }
        }
        while (i >= 0)
            B[k++] = A[i] * A[i], i--;
        while (j < length)
            B[k++] = A[j] * A[j], j++;
        return B;
    }
};