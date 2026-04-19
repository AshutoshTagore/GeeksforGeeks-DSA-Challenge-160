/* 0 - 1 Knapsack Problem */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = val.size();
        vector<int> dp(W + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);       
            }
        }
        return dp[W];
    }
};