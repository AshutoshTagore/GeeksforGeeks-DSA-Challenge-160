/* Que.13) You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.*/



#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& arr) {
    int n = arr.size();

    //Place numbers at correct index
    for(int i = 0; i < n; i++) {
        while(arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    //Find first missing positive
    for(int i = 0; i < n; i++) {
        if(arr[i] != i + 1) {
            return i + 1;
        }
    }

    //If all 1..n present, answer is n+1
    return n + 1;
}

int main() {
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr) << endl; // Output: 3
    return 0;
}