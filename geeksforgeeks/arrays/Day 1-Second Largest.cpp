/* Que.1) Given an array of positive integers arr[], 
return the second largest element from the array. 
If the second largest element doesn't exist then return -1.*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int getSecondLargest(vector<int>& arr) {
    int n = arr.size();
    int largest = arr[0];
    int seclargest = INT_MIN;

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            seclargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > seclargest) {
            seclargest = arr[i];
        }
    }

    if(seclargest == INT_MIN) {
        return -1;
    }
    return seclargest;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};

    int result = getSecondLargest(arr);

    cout << "Second largest element from array: " << result << endl;

    return 0;
}