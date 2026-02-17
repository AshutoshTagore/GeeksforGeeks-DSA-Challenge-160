/* Que.62) Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.  */
    


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lenOfLongestSubarr(vector<int>& arr, int k) {
            unordered_map<int, int> mp;
            int sum = 0, res = 0;
            for (int i = 0; i < arr.size(); ++i) {
                sum += arr[i];
                if (sum == k) res = i + 1;
                if (mp.count(sum - k)) res = max(res, i - mp[sum - k]);
                if (!mp.count(sum)) mp[sum] = i;
            }
            return res;
        }
};

int main() {
    Solution obj;
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << obj.lenOfLongestSubarr(arr, k) << endl; // Output: 6
    return 0;
}