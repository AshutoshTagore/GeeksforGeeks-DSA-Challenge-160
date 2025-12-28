/* Que.2) You are given an array arr[] of non-negative integers. 
You have to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. 
The operation must be performed in place, meaning you should not use extra space for another array.*/


#include <iostream>
#include <vector>
using namespace std;

void moveZeros(vector<int>& arr) {
    int n = arr.size();
    int pos = 0;  // position to place next non-zero

    // Step 1: Move non-zero elements forward
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    // Step 2: Fill remaining positions with zeros
    while(pos < n) {
        arr[pos] = 0;
        pos++;
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};

    moveZeros(arr);

    cout << "Array after moving zeros: ";
    for(int x : arr) {
        cout << x << " ";
    }
    return 0;
}