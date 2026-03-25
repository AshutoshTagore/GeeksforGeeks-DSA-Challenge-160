/* Que.98) Find median in a stream  */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> maxHeap; 
        
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        
        vector<double> ans;

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            maxHeap.push(num);
            
            if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } 
            else if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (maxHeap.size() == minHeap.size()) {
                ans.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            } else {
                ans.push_back(maxHeap.top());
            }
        }
        
        return ans;
    }
};