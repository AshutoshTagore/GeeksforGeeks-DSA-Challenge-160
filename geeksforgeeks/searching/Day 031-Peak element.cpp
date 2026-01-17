/* Que.31) You are given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist).
If there are multiple peak elements, Return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

Note: Consider the element before the first element and the element after the last element to be negative infinity. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakElement(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] < arr[mid + 1]) {
                // Peak must be on right side
                low = mid + 1;
            } else {
                // Peak must be on left side or mid itself
                high = mid;
            }
        }
        return low; // low == high → peak index
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {1,2,4,5,7,8,3};
    cout << obj.peakElement(arr1) << endl; // Output: 5

    vector<int> arr2 = {10,20,15,2,23,90,80};
    cout << obj.peakElement(arr2) << endl; // Output: 1 or 5

    return 0;
}