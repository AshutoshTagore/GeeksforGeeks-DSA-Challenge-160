/* Que.104) Max of min for every window size */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }
        for (int i = n - 1; i >= 1; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        vector<int> finalAns(ans.begin() + 1, ans.end());
        return finalAns;
    }
};