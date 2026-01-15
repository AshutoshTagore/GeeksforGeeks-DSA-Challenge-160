/* Que.29) A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int findMin(vector<int>& arr) {
          int n = arr.size();
          int low = 0, high = n - 1, mid = 0;
  
          while(low < high) {
              mid = low + (high - low) / 2;
              if(arr[mid] <= arr[high]) 
                  high = mid;
              else 
                  low = mid + 1;
          }
          return arr[low]; 
      }
  };

  int main() {
    Solution obj;

    vector<int> arr1 = {5,6,1,2,3,4};
    cout << obj.findMin(arr1) << endl; // Output: 1

    vector<int> arr2 = {3,1,2};
    cout << obj.findMin(arr2) << endl; // Output: 1

    vector<int> arr3 = {4,2,3};
    cout << obj.findMin(arr3) << endl; // Output: 2

    return 0;
}
