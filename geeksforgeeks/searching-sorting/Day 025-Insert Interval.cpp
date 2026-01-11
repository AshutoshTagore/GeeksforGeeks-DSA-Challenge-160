/* Que.25) Geek has an array of non-overlapping intervals intervals[][] where intervals[i] = [starti , endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti . He wants to add a new interval newInterval[] = [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.
Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Add all intervals before newInterval
        while(i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Add remaining intervals
        while(i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> intervals1 = {{1,3},{4,5},{6,7},{8,10}};
    vector<int> newInterval1 = {5,6};
    auto res1 = obj.insertInterval(intervals1, newInterval1);
    for(auto &v : res1) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // Output: [1,3] [4,7] [8,10]

    vector<vector<int>> intervals2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval2 = {4,9};
    auto res2 = obj.insertInterval(intervals2, newInterval2);
    for(auto &v : res2) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl; // Output: [1,2] [3,10] [12,16]

    return 0;
}