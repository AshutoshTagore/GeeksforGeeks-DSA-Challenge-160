/* Que.26) Given a 2D array intervals[][], where intervals[i] = [starti, endi]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note: Two intervals are considered non-overlapping if the end time of one interval is less than or equal to the start time of the next interval.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int minRemoval(vector<vector<int>> &intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){return a[1] < b[1];});

        // Greedy selection
        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < prevEnd){
                count++;
            }
            else {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};
  
int main() {
    Solution obj;

    vector<vector<int>> arr1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << obj.minRemoval(arr1) << endl; // Output: 1

    vector<vector<int>> arr2 = {{1,3},{1,3},{1,3}};
    cout << obj.minRemoval(arr2) << endl; // Output: 2

    vector<vector<int>> arr3 = {{1,2},{5,10},{18,35},{40,45}};
    cout << obj.minRemoval(arr3) << endl; // Output: 0

    return 0;
}