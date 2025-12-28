/* Que.11) Given an array arr[] that contains positive and negative integers (may contain 0 as well). 
Find the maximum product that we can get in a subarray of arr[].
Note: It is guaranteed that the answer fits in a 32-bit integer.*/


#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& arr) {
    int n = arr.size();
    int maxProd = arr[0];
    int minProd = arr[0];
    int result = arr[0];

    for(int i = 1; i < n; i++) {
        int temp = maxProd;

        maxProd = max({arr[i], arr[i] * maxProd, arr[i] * minProd});
        minProd = min({arr[i], arr[i] * temp, arr[i] * minProd});

        result = max(result, maxProd);
    }

    return result;
}

int main() {
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << maxProduct(arr) << endl; // Output: 180
    return 0;
}