/* Que.103) Histogram Max Rectangular Area  */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMaxArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxArea = 0;
        
        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : arr[i];
            
            while (!st.empty() && currHeight < arr[st.top()]) {
                int h = arr[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) {
                    width = i; 
                } else {
                    width = i - st.top() - 1; 
                }
                
                maxArea = max(maxArea, h * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};