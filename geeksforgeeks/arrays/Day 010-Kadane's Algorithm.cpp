/* Que.10) You are given an integer array arr[]. 
You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].
Note : A subarray is a continuous part of an array.*/


#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int>& arr) {
    int current_sum = arr[0];
    int max_sum = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        // Decide: start new subarray OR extend previous
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubArraySum(arr) << endl; // Output: 11
    return 0;
}