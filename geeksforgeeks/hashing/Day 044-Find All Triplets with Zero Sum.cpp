/* Que.44) Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k. */



#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> findTriplets(vector<int>& arr) {
            vector<vector<int>> res;
            int n = arr.size();
            for (int i = 0; i < n - 2; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (arr[i] + arr[j] + arr[k] == 0) {
                            res.push_back({i, j, k});
                        }
                    }
                }
            }
    
            return res;
        }
    };

int main() {
    Solution obj;

    vector<int> arr1 = {0, -1, 2, -3, 1};
    auto res1 = obj.findTriplets(arr1);
    for(auto triplet : res1) {
        cout << "[";
        for(int idx=0; idx<triplet.size(); idx++) {
            cout << triplet[idx];
            if(idx < triplet.size()-1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    vector<int> arr2 = {1, -2, 1, 0, 5};
    auto res2 = obj.findTriplets(arr2);
    for(auto triplet : res2) {
        cout << "[";
        for(int idx=0; idx<triplet.size(); idx++) {
            cout << triplet[idx];
            if(idx < triplet.size()-1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    vector<int> arr3 = {2, 3, 1, 0, 5};
    auto res3 = obj.findTriplets(arr3);
    for(auto triplet : res3) {
        cout << "[";
        for(int idx=0; idx<triplet.size(); idx++) {
            cout << triplet[idx];
            if(idx < triplet.size()-1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}