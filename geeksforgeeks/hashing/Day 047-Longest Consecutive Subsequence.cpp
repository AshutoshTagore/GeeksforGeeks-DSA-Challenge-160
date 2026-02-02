/* Que.47) Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end()); 
        int longest = 0;

        for(int num : arr) {
            if(s.find(num - 1) == s.end()) {
                int currentNum = num;
                int length = 1;

                while(s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {2, 6, 1, 9, 4, 5, 3};
    cout << obj.longestConsecutive(arr1) << endl; // Output: 6

    vector<int> arr2 = {1, 9, 3, 10, 4, 20, 2};
    cout << obj.longestConsecutive(arr2) << endl; // Output: 4

    vector<int> arr3 = {15, 13, 12, 14, 11, 10, 9};
    cout << obj.longestConsecutive(arr3) << endl; // Output: 7

    return 0;
}