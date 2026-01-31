/* Que.45) Given two integer arrays a[] and b[], you have to find the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both the arrays. The intersection should not have duplicate elements and the result should contain items in any order.
Note: The driver code will sort the resulting array in increasing order before printing.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> intersect(vector<int>& a, vector<int>& b) {
          vector<int> ans;
          unordered_map<int,int> m;
          for(int x : a) m[x]=1;
          for(int x : b){
              if(m[x]){
                  ans.push_back(x);
                  m[x]=0;
              }
          }
          return ans;
    }
};

int main() {
    Solution obj;

    vector<int> a1 = {1, 2, 1, 3, 1};
    vector<int> b1 = {3, 1, 3, 4, 1};
    auto res1 = obj.intersect(a1, b1);
    for(int x : res1) cout << x << " ";
    cout << endl; // Output: 1 3 
    
    vector<int> a2 = {1, 1, 1};
    vector<int> b2 = {1, 1, 1, 1, 1};
    auto res2 = obj.intersect(a2, b2);
    for(int x : res2) cout << x << " ";
    cout << endl; // Output: 1

    vector<int> a3 = {1, 2, 3};
    vector<int> b3 = {4, 5, 6};
    auto res3 = obj.intersect(a3, b3);
    for(int x : res3) cout << x << " ";
    cout << endl; // Output: (empty)

    return 0;
}
