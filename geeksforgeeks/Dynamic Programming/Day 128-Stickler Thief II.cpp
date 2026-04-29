/* Stickler Thief II */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int robLinear(vector<int>& arr, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;
        
        for (int i = start; i <= end; i++) {
            int current_max = max(arr[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current_max;
        }
        return prev1;
    }

  public:
    int maximizeLoot(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        int case1 = robLinear(arr, 0, n - 2);
        int case2 = robLinear(arr, 1, n - 1);
        return max(case1, case2);
    }
};