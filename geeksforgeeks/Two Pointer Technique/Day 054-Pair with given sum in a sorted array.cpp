/* Que.54) You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order. */



#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int l = 0 , r = n-1, count = 0;
        
        while(l < r){
            int sum = arr[l] + arr[r];
            
            if(sum == target){
                if(arr[l] == arr[r]){
                    int len = r -l + 1;
                    count+=(len*(len - 1)) /  2;
                    break;
                }else{
                    int left = 1, right = 1;
                    while(l < r and arr[l] == arr[l+1]){
                        left++;
                        l++;
                    }
                    while(l < r and arr[r] == arr[r-1]){
                        right++;
                        r--;
                    }
                    count +=(left*right);
                    l++;
                    r--;
                }
            }
            else if(sum < target) l++;
                else r--;
        }
        return count;
    }
};


int main() {
    Solution obj;

    vector<int> arr1 = {-1, 1, 5, 5, 7};
    cout << obj.countPairs(arr1, 6) << endl; // Output: 3

    vector<int> arr2 = {1, 1, 1, 1};
    cout << obj.countPairs(arr2, 2) << endl; // Output: 6

    vector<int> arr3 = {-1, 10, 10, 12, 15};
    cout << obj.countPairs(arr3, 125) << endl; // Output: 0

    return 0;
}
