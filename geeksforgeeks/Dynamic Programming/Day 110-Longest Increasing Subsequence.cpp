/* Que.110) Longest Increasing Subsequence */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
        vector<int> ans;
        
        for (int i = 0; i < arr.size(); i++) {
            
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            
            if (it == ans.end()) {
                ans.push_back(arr[i]);
            } 
            else {
                *it = arr[i];
            }
        }
        return ans.size();
    }
};