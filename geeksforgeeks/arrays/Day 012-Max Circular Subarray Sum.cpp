/* Que.12) You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. 
In a circular array, the subarray can start at the end and wrap around to the beginning. 
Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.*/


#include <bits/stdc++.h>
using namespace std;

int maxCircularSum(vector<int> &arr) {
    int totalSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int currMax = 0;
    int currMin = 0;

    for(int i = 0; i < arr.size(); i++) {
        totalSum += arr[i];

        // Case 1: Normal max subarray (Kadane's)
        currMax = max(arr[i], currMax + arr[i]);
        maxSum = max(maxSum, currMax);

        // Case 2: Minimum subarray (for circular logic)
        currMin = min(arr[i], currMin + arr[i]);
        minSum = min(minSum, currMin);
    }

    // Case 3: If all elements are negative
    if(maxSum < 0) return maxSum;

    // Case 4: Circular subarray sum
    return max(maxSum, totalSum - minSum);
}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << maxCircularSum(arr) << endl; // Output: 22
    return 0;
}