/* Que.52) Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        int count = 0;

        int l = 0, r = n-1;
        while(l < r) {
            if(arr[l] + arr[r] < target) {
                count += (r - l); // all pairs with arr[l] are valid
                l++;
            } else {
                r--;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {7, 2, 5, 3};
    cout << obj.countPairs(arr1, 8) << endl; // Output: 2

    vector<int> arr2 = {5, 2, 3, 2, 4, 1};
    cout << obj.countPairs(arr2, 5) << endl; // Output: 4

    vector<int> arr3 = {2, 1, 8, 3, 4, 7, 6, 5};
    cout << obj.countPairs(arr3, 7) << endl; // Output: 6

    return 0;
}