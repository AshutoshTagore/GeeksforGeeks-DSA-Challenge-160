/* Que.51) Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int countTriplets(vector<int> &arr, int target) {
          int n = arr.size();
          int count = 0;
          
          for(int i = 0; i < n-2; i++){
              int left = i+1, right = n-1;
              
              while(left < right){
                  int sum = arr[i] + arr[left] + arr[right];
                  
                  if(sum == target){
                    // all elements are same nc2
                      if(arr[left] == arr[right]){
                          int length = right - left + 1;
                          count += (length*(length-1)) / 2;
                          break;
                      }
                      // count left duplicates
                      int leftCount = 1;
                      while(left+1 < right && arr[left] == arr[left+1]){
                          left++;
                          leftCount++;
                      }
                      // count right duplicates
                      int rightCount = 1;
                      while(right-1 > left && arr[right] == arr[right-1]){
                          right--;
                          rightCount++;
                      }
                      count+= leftCount*rightCount;
                      left++;
                      right--;
                  }
                  else if(sum > target){
                      right--;
                  }
                  else{
                      left++;
                  }
              }
          }
          return count;
      }
  };

int main() {
    Solution obj;

    vector<int> arr1 = {-3, -1, -1, 0, 1, 2};
    cout << obj.countTriplets(arr1, -2) << endl; 

    vector<int> arr2 = {-2, 0, 1, 1, 5};
    cout << obj.countTriplets(arr2, 1) << endl;

    return 0;
}