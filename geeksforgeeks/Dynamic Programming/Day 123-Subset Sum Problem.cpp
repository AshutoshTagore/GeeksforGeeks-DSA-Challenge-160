/* Subset Sum Problem */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            for (int s = sum; s >= arr[i]; s--) {
                dp[s] = dp[s] || dp[s - arr[i]];
            }
        }
        return dp[sum];
    }
};