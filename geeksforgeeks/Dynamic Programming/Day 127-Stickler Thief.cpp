/* Stickler Thief */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int FindMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        int prev2 = 0;   
        int prev1 = arr[0];   
        
        for (int i = 1; i < n; i++) {
            int take = arr[i] + prev2;
            int notTake = prev1;
            int current_max = max(take, notTake);
            prev2 = prev1;
            prev1 = current_max;
        }
        return prev1;
    }
};