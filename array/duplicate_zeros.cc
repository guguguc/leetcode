#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void duplicateZeros(vector<int>& arr) {
      int count = 0, i = 0, j = 0;
      for (; i+count+1 < arr.size(); ++i)
          if (arr[i] == 0) ++count, j = i;
      for (; i >=0 && count > 0; --i) {
          arr[i+count] = arr[i];
          if (!arr[i] && i < j) arr[--count+i] = 0;
      }
  }
};
