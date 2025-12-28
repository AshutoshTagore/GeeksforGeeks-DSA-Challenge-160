/* Que.3) You are given an array of integers arr[]. You have to reverse the given array.*/


#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr) {
    int i = 0;              // array first element
    int j = arr.size() - 1;      //array Last element

    while(i < j) {
        swap(arr[i], arr[j]);             
        i++;
        j--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    reverseArray(arr);

    cout << "Array after reversing: ";
    for(int x : arr) {
        cout << x << " ";
    }
    return 0;
}