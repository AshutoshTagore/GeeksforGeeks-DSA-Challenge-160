/* Que.6) Given an array arr[] consisting of n integers, 
the task is to find all the array elements which occurs more than floor(n/3) times.

Note: The returned array of majority elements should be sorted.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,int> freq;

    // Count frequency
    for(int x : arr) {
        freq[x]++;
    }

    vector<int> result;
    for(auto &p : freq) {
        if(p.second > n/3) {
            result.push_back(p.first);
        }
    }

    sort(result.begin(), result.end()); // sorted output
    return result;
}

int main() {
    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> ans = findMajority(arr);

    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}