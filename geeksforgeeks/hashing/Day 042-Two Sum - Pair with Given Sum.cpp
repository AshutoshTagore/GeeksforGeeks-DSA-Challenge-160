/* Que.42) Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that the sum of their elements is equal to the target. */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> seen;

        for(int num : arr) {
            int complement = target - num;
            if(seen.find(complement) != seen.end()) {
                return true; // pair found
            }
            seen.insert(num);
        }
        return false; // no pair found
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {0, -1, 2, -3, 1};
    cout << (obj.twoSum(arr1, -2) ? "true" : "false") << endl; // true

    vector<int> arr2 = {1, -2, 1, 0, 5};
    cout << (obj.twoSum(arr2, 0) ? "true" : "false") << endl; // false

    vector<int> arr3 = {11};
    cout << (obj.twoSum(arr3, 11) ? "true" : "false") << endl; // false

    return 0;
}