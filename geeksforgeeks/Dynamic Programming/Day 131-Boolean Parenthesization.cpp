/* Boolean Parenthesization */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(string& s, int i, int j, int isTrue, vector<vector<vector<int>>>& dp) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue == 1) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        long long ways = 0; 
        for (int k = i + 1; k <= j - 1; k += 2) {
            long long leftT = solve(s, i, k - 1, 1, dp);
            long long leftF = solve(s, i, k - 1, 0, dp);
            long long rightT = solve(s, k + 1, j, 1, dp);
            long long rightF = solve(s, k + 1, j, 0, dp);
            
            if (s[k] == '&') {
                if (isTrue) {
                    ways += (leftT * rightT);
                } else {
                    ways += (leftT * rightF) + (leftF * rightT) + (leftF * rightF);
                }
            } 
            else if (s[k] == '|') {
                if (isTrue) {
                    ways += (leftT * rightT) + (leftT * rightF) + (leftF * rightT);
                } else {
                    ways += (leftF * rightF);
                }
            } 
            else if (s[k] == '^') {
                if (isTrue) {
                    ways += (leftT * rightF) + (leftF * rightT);
                } else {
                    ways += (leftT * rightT) + (leftF * rightF);
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }

  public:
    int countWays(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(s, 0, n - 1, 1, dp);
    }
};