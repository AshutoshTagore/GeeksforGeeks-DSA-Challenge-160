/* Que.43) You are given an array arr[] and an integer target. You have to count all pairs in the array such that their sum is equal to the given target. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        unordered_map<int,int> freq;
        int count = 0;

        for(int num : arr) {
            int complement = target - num;

            if(freq.find(complement) != freq.end()) {
                count += freq[complement];
            }

            freq[num]++;
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {1, 5, 7, -1, 5};
    cout << obj.countPairs(arr1, 6) << endl; // Output: 3

    vector<int> arr2 = {1, 1, 1, 1};
    cout << obj.countPairs(arr2, 2) << endl; // Output: 6

    vector<int> arr3 = {10, 12, 10, 15, -1};
    cout << obj.countPairs(arr3, 125) << endl; // Output: 0

    return 0;
}