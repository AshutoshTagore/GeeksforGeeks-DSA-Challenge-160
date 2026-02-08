/* Que.53) Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a ≤ b whose sum is closest to target.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestPair(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> res;
        int minDiff = INT_MAX;
        int l = 0, r = n - 1;

        while(l < r) {
            int sum = arr[l] + arr[r];
            int diff = abs(sum - target);
            
            if(diff < minDiff) {
                minDiff = diff;
                res = {arr[l], arr[r]};
            }
            
            if(sum < target) {
                l++;
            } else {
                r--;
            }
        }
        
        return res;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {10, 30, 20, 5};
    auto res1 = obj.closestPair(arr1, 25);
    for(int x : res1) cout << x << " "; // Output: 5 20
    cout << endl;

    vector<int> arr2 = {5, 2, 7, 1, 4};
    auto res2 = obj.closestPair(arr2, 10);
    for(int x : res2) cout << x << " "; // Output: 2 7
    cout << endl;

    vector<int> arr3 = {10};
    auto res3 = obj.closestPair(arr3, 10);
    if(res3.empty()) cout << "[]"; // Output: []
    cout << endl;

    return 0;
}