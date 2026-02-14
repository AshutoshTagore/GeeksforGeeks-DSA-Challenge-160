/* Que.59) You are given a string s. You have to find the length of the longest substring with all distinct characters.  */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long trappingWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        
        int maxLeft = 0;
        int maxRight = 0;
        
        long long totalWater = 0; 
        
        while (left <= right) {
            
            if (arr[left] <= arr[right]) {
                if (arr[left] >= maxLeft) {
                    maxLeft = arr[left];
                } else {
                    totalWater += (maxLeft - arr[left]);
                }
                left++;
            } 
            else {
                if (arr[right] >= maxRight) {
                    maxRight = arr[right];
                } else {
                    totalWater += (maxRight - arr[right]);
                }
                right--;
            }
        }
        
        return totalWater;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {3, 0, 1, 0, 4, 0, 2};
    cout << "Trapped Water: " << obj.trappingWater(arr) << endl; // Output: 10
    return 0;
}