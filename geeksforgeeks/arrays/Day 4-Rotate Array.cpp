/* Que.4) Given an array arr[].
Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. 
Do the mentioned change in the array in place.
Note: Consider the array as circular.*/


#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

void rotateArray(vector<int>& arr, int d) {
    int n = arr.size();
    if(n == 0) return;

    d = d % n; // handle cases where d > n

    // Step 1: reverse first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Step 2: reverse remaining n-d elements
    reverse(arr.begin() + d, arr.end());

    // Step 3: reverse whole array
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2; // rotate left by 2 steps

    rotateArray(arr, d);

    cout << "Array after rotation: ";
    for(int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}