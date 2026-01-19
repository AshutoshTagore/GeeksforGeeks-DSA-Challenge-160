/* Que.33) You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int>& stalls, int k, int dist) {
        int count = 1; // first cow at stalls[0]
        int lastPos = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPos >= dist) {
                count++;
                lastPos = stalls[i];
            }
            if(count >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls.back() - stalls.front();
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canPlace(stalls, k, mid)) {
                ans = mid;
                low = mid + 1; // try bigger distance
            } else {
                high = mid - 1; // try smaller distance
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> stalls1 = {1,2,4,8,9};
    cout << obj.aggressiveCows(stalls1, 3) << endl; // Output: 3

    vector<int> stalls2 = {10,1,2,7,5};
    cout << obj.aggressiveCows(stalls2, 3) << endl; // Output: 4

    vector<int> stalls3 = {2,12,11,3,26,7};
    cout << obj.aggressiveCows(stalls3, 5) << endl; // Output: 1

    return 0;
}