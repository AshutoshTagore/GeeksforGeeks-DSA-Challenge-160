/* Que.64) Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[]. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1);

        int left_product = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left_product;
            left_product *= arr[i];
        }
        
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right_product;
            right_product *= arr[i];
        }
        
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> ans = obj.productExceptSelf(arr);
    
    for(auto x : ans) cout << x << " ";     // Output: 180 600 360 300 900
    cout << endl; 
    return 0;
}