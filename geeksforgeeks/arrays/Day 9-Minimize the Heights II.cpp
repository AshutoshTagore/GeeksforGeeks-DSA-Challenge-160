/* Que.9) Given an array arr[] denoting heights of n towers and a positive integer k.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by k
Decrease the height of the tower by k
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.*/


#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int>& arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int ans = arr[n-1] - arr[0]; // initial difference

    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;

    for(int i = 0; i < n-1; i++) {
        int min_height = min(smallest, arr[i+1] - k);
        int max_height = max(largest, arr[i] + k);
        if(min_height < 0) continue; // negative height not allowed
        ans = min(ans, max_height - min_height);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    cout << getMinDiff(arr, k) << endl; // Output: 5
    return 0;
}