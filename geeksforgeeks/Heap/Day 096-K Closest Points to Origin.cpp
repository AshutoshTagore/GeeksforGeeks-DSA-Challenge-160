/* Que.96) K Closest Points to Origin */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxh;
        
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            int dist = (x * x) + (y * y);
            
            maxh.push({dist, points[i]});
            
            if (maxh.size() > k) {
                maxh.pop();
            }
        }
        
        vector<vector<int>> ans;
        while (!maxh.empty()) {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        
        return ans;
    }
};