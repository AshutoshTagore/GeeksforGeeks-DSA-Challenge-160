/* Que.111) Longest String Chain */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool comp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        
        unordered_map<string, int> dp;
        int max_chain = 1;
        
        for (string word : words) {
            dp[word] = 1;
            
            for (int i = 0; i < word.length(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                
                if (dp.find(predecessor) != dp.end()) {
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }
            max_chain = max(max_chain, dp[word]);
        }
        return max_chain;
    }
};