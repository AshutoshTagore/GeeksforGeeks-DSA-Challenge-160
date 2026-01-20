/* Que.34) Allocate Minimum Pages */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int maxPages) {
        int students = 1;
        int pages = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > maxPages) return false; // single book > maxPages -> not possible

            if(pages + arr[i] > maxPages) {
                students++;
                pages = arr[i];
                if(students > k) return false;
            } else {
                pages += arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if(k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1; // try smaller maximum
            } else {
                low = mid + 1; // increase maximum
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {12,34,67,90};
    cout << obj.findPages(arr1, 2) << endl; // Output: 113

    vector<int> arr2 = {15,17,20};
    cout << obj.findPages(arr2, 5) << endl; // Output: -1

    return 0;
}