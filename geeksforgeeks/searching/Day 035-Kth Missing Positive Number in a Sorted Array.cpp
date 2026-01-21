/* Que.35) Given a sorted array of distinct positive integers arr[], You need to find the kth positive number that is missing from the arr[]. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int KthMissing(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if(missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {2,3,4,7,11};
    cout << obj.KthMissing(arr1, 5) << endl; // Output: 9

    vector<int> arr2 = {1,2,3};
    cout << obj.KthMissing(arr2, 2) << endl; // Output: 5

    vector<int> arr3 = {3,5,9,10,11,12};
    cout << obj.KthMissing(arr3, 2) << endl; // Output: 2

    return 0;
}