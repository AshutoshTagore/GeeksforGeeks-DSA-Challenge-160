/* Que.46) Union of Arrays with Duplicates */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s;

        for(int num : a) s.insert(num);

        for(int num : b) s.insert(num);

        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> a1 = {1, 2, 3, 2, 1};
    vector<int> b1 = {3, 2, 2, 3, 3, 2};
    auto res1 = obj.findUnion(a1, b1);
    for(int x : res1) cout << x << " ";
    cout << endl; // Output: 1 2 3 

    vector<int> a2 = {1, 2, 3};
    vector<int> b2 = {4, 5, 6};
    auto res2 = obj.findUnion(a2, b2);
    for(int x : res2) cout << x << " ";
    cout << endl; // Output: 1 2 3 4 5 6

    vector<int> a3 = {1, 2, 1, 1, 2};
    vector<int> b3 = {2, 2, 1, 2, 1};
    auto res3 = obj.findUnion(a3, b3);
    for(int x : res3) cout << x << " ";
    cout << endl; // Output: 1 2

    return 0;
}