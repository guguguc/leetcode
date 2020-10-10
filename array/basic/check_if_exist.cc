#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, bool> hash;
        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            if (hash.count(num)) {
                return true;
            } else {
                hash[2*num] = true;
                if (!(num%2)) hash[num/2] = true;
            }
        }
        return false;
    }
};
int main()
{
    vector<int> v{1, 2, 4, 0};
    // vector<int> v{1, 4, 2, 0};
    // vector<int> v{1, 4, 4, 0};
    bool ans = Solution().checkIfExist(v);
    cout << ans << endl;
    return 0;
}
