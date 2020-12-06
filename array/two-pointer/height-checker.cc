#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker_vanilla(vector<int> &heights)
    {
        vector<int> aux(heights);
        sort(aux.begin(), aux.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i)
            if (aux[i] != heights[i])
                ++ans;
        return ans;
    }
};

int main()
{
    vector<int> a({5, 1, 2, 3, 4});
    int ans = Solution().heightChecker_vanilla(a);
    cout << ans;
    return 0;
}
