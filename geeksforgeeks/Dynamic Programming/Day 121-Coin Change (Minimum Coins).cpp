/* Coin Change (Minimum Coins) */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int INF = sum + 1; 
        vector<int> dp(sum + 1, INF);
        
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int curr_sum = coins[i]; curr_sum <= sum; curr_sum++) {
                dp[curr_sum] = min(dp[curr_sum], 1 + dp[curr_sum - coins[i]]);
                
            }
        }
        return dp[sum] == INF ? -1 : dp[sum];
    }
};