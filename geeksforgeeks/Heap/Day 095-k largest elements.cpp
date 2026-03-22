/* Que.95) Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order.  */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
        int n = arr.size();
          priority_queue<int, vector<int>, greater<int>> pq;
          for(int i=0; i<k; i++)pq.push(arr[i]);
          for(int i=k; i<n; i++){
              if(arr[i]>pq.top()){
                  pq.pop();
                  pq.push(arr[i]);
              }
          }
          vector<int> ans(k,0);
          int i=0;
          while(pq.size()){
              ans[k-1-i] = pq.top();
              pq.pop();
              i++;
          }
          return ans;
      }
  };

int main() {
    Solution sol;
    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int n = arr.size();
    int k = 3;
    vector<int> result = sol.kLargest(arr, k);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}