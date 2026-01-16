/* Que.30) Given an array arr[] of distinct elements, which was initially sorted in ascending order but then rotated at some unknown pivot, the task is to find the index of a target key.  
If the key is not present in the array, return -1. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0, high = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] == key) return mid;

            // Left half sorted
            if(arr[low] <= arr[mid]) {
                if(key >= arr[low] && key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half sorted
            else {
                if(key > arr[mid] && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {5,6,7,8,9,10,1,2,3};
    cout << obj.search(arr1, 3) << endl; // Output: 8

    vector<int> arr2 = {3,5,1,2};
    cout << obj.search(arr2, 6) << endl; // Output: -1

    vector<int> arr3 = {33,42,72,99};
    cout << obj.search(arr3, 42) << endl; // Output: 1

    return 0;
}