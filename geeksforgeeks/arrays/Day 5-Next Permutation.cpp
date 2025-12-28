/* Que.5) Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. 
If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

Note:  A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;

    // Step 1: Find pivot
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Step 2: Find successor
        int j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }
        // Step 3: Swap pivot and successor
        swap(arr[i], arr[j]);
    }

    // Step 4: Reverse suffix
    reverse(arr.begin() + i + 1, arr.end());
}

int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};

    nextPermutation(arr);

    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}