/* Partition Equal Subset Sum */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPartition(vector<int>& arr) {
        int total_sum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
        }
        if (total_sum % 2 != 0) {
            return false;
        }
        int target = total_sum / 2;
        
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            for (int s = target; s >= arr[i]; s--) {
                dp[s] = dp[s] || dp[s - arr[i]];
            }
        }
        return dp[target];
    }
};