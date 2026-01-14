/* Que.28) Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[].*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFirst(vector<int>& arr, int target) {
        int st = 0, end = arr.size() - 1, ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] == target) {
                ans = mid;
                end = mid - 1; // Keep looking left
            } else if (arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& arr, int target) {
        int st = 0, end = arr.size() - 1, ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] == target) {
                ans = mid;
                st = mid + 1; // Keep looking right
            } else if (arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = findFirst(arr, target);
        if (first == -1) return 0; // Target not found
        int last = findLast(arr, target);
        return (last - first + 1);
    }
};

int main() {
    Solution obj;
    vector<int> arr1 = {1, 1, 2, 2, 2, 2, 3};
    int target1 = 2; 
    cout << "Frequency: " << obj.countFreq(arr1, target1) << endl; 
    return 0;
}