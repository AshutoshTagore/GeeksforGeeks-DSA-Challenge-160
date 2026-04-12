/* Que.113) Longest Palindromic Subsequence */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestPalinSubseq(string s) {
        int n = s.length();
        
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == s_rev[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } 
                else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};