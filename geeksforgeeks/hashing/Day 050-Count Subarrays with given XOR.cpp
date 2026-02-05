/* Que.50) Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayXor(vector<int>& arr, int k) {
        unordered_map<int,int> freq; 
        int xr = 0, count = 0;

        for(int num : arr) {
            xr ^= num; 

            if(xr == k) count++;

            if(freq.find(xr ^ k) != freq.end()) {
                count += freq[xr ^ k];
            }

            freq[xr]++;
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {4, 2, 2, 6, 4};
    cout << obj.subarrayXor(arr1, 6) << endl; // Output: 4

    vector<int> arr2 = {5, 6, 7, 8, 9};
    cout << obj.subarrayXor(arr2, 5) << endl; // Output: 2

    vector<int> arr3 = {1, 1, 1, 1};
    cout << obj.subarrayXor(arr3, 0) << endl; // Output: 4

    return 0;
}