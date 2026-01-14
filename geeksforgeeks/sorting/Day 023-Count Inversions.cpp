/* Que.23) Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int merge(vector<int> &arr, int st, int mid, int end) {
        vector<int> temp;
        int i = st, j = mid + 1;
        int invcount = 0;

        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
                invcount += (mid - i + 1); 
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= end) { 
            temp.push_back(arr[j]);
            j++;
        }

        for (int idx = 0; idx < temp.size(); idx++) {
            arr[idx + st] = temp[idx];
        }

        return invcount;
    }

    int mergesort(vector<int> &arr, int st, int end) {
        if (st >= end) return 0;
        
        int mid = st + (end - st) / 2;
        int leftInv = mergesort(arr, st, mid);
        int rightInv = mergesort(arr, mid + 1, end);
        int mergeInv = merge(arr, st, mid, end);
        
        return leftInv + rightInv + mergeInv;
    }

    int inversionCount(vector<int> &arr) {
        return mergesort(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {6, 3, 5, 2, 7};
    Solution obj;
    int ans = obj.inversionCount(arr); 

    cout << "Inversion Count is: " << ans << endl;    // Output: Inversion Count is: 5
}
