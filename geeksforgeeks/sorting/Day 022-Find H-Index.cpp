/* Que.22) You are given an array citations[], where each element citations[i] represents the number of citations received by the ith paper of a researcher. You have to calculate the researcher’s H-index.
The H-index is defined as the maximum value H, such that the researcher has published at least H papers, and all those papers have citation value greater than or equal to H.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for(int i = 0; i < n; i++){
            int h = n-i;
            if(citations[i] >= h) return h;
        }
        return 0;
    }
};

int main() {
    Solution obj;
    vector<int> citations1 = {3, 0, 5, 3, 0};
    cout << obj.hIndex(citations1) << endl; // Output: 3

    vector<int> citations2 = {5, 1, 2, 4, 1};
    cout << obj.hIndex(citations2) << endl; // Output: 2

    vector<int> citations3 = {0, 0};
    cout << obj.hIndex(citations3) << endl; // Output: 0

    return 0;
}