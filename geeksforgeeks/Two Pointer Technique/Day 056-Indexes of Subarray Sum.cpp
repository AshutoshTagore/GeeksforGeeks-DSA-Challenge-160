/* Que.56) Indexes of Subarray Sum. */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int start = 0;
        int currSum = 0;

        for(int end = 0; end < n; end++) {
            currSum += arr[end];

            while(currSum > target && start < end) {
                currSum -= arr[start];
                start++;
            }

            if(currSum == target) {
                return {start+1, end+1}; 
            }
        }
        return {-1};
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {1, 2, 3, 7, 5};
    auto res1 = obj.subarraySum(arr1, 12);
    for(int x : res1) cout << x << " "; // Output: 2 4
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto res2 = obj.subarraySum(arr2, 15);
    for(int x : res2) cout << x << " "; // Output: 1 5
    cout << endl;

    vector<int> arr3 = {5, 3, 4};
    auto res3 = obj.subarraySum(arr3, 2);
    for(int x : res3) cout << x << " "; // Output: -1
    cout << endl;

    return 0;
}