/* Que.49) Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> prefixFreq; 
        int sum = 0, count = 0;

        for(int num : arr) {
            sum += num; 

            if(sum == k) count++;

            if(prefixFreq.find(sum - k) != prefixFreq.end()) {
                count += prefixFreq[sum - k];
            }

            prefixFreq[sum]++;
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {10, 2, -2, -20, 10};
    cout << obj.subarraySum(arr1, -10) << endl; // Output: 3

    vector<int> arr2 = {9, 4, 20, 3, 10, 5};
    cout << obj.subarraySum(arr2, 33) << endl; // Output: 2

    vector<int> arr3 = {1, 3, 5};
    cout << obj.subarraySum(arr3, 0) << endl; // Output: 0

    return 0;
}