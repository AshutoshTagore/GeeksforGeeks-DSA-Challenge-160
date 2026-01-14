/* Que.24) Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
        vector<vector<int>> result;
        if(arr.empty()) return result;

        //Sort intervals by start time
        sort(arr.begin(), arr.end());

        //Traverse and merge
        result.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i][0] <= result.back()[1]) {
                // Overlap → merge
                result.back()[1] = max(result.back()[1], arr[i][1]);
            } else {
                // No overlap → add new interval
                result.push_back(arr[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> arr1 = {{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> res1 = obj.mergeIntervals(arr1);
    for(auto &v : res1) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // Output: [1,4] [6,8] [9,10]

    vector<vector<int>> arr2 = {{6,8},{1,9},{2,4},{4,7}};
    vector<vector<int>> res2 = obj.mergeIntervals(arr2);
    for(auto &v : res2) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // Output: [1,9]

    return 0;
}