/* Que.60) You are given a string s. You have to find the length of the longest substring with all distinct characters.  */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;
        int maxArea = 0; 

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            
            int currentArea = width * height;
            maxArea = max(maxArea, currentArea);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 5, 4, 3};
    cout << "Max Water: " << obj.maxWater(arr) << endl; // Output: 6
    return 0;
}

