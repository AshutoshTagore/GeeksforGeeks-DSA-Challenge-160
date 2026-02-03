/* Que.48) Given an array of strings, return all groups of strings that are anagrams. The strings in each group must be arranged in the order of their appearance in the original array. Refer to the sample case for clarification. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;

        for(string s : arr) {
            string key = s;
            sort(key.begin(), key.end()); 
            mp[key].push_back(s);    
        }

        vector<vector<string>> res;
        for(auto &it : mp) {
            res.push_back(it.second);    
        }
        return res;
    }
};

int main() {
    Solution obj;

    vector<string> arr1 = {"act", "god", "cat", "dog", "tac"};
    auto res1 = obj.groupAnagrams(arr1);
    for(auto group : res1) {
        cout << "[ ";
        for(auto s : group) cout << s << " ";
        cout << "] ";
    }
    cout << endl;

    vector<string> arr2 = {"no", "on", "is"};
    auto res2 = obj.groupAnagrams(arr2);
    for(auto group : res2) {
        cout << "[ ";
        for(auto s : group) cout << s << " ";
        cout << "] ";
    }
    cout << endl;

    vector<string> arr3 = {"listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"};
    auto res3 = obj.groupAnagrams(arr3);
    for(auto group : res3) {
        cout << "[ ";
        for(auto s : group) cout << s << " ";
        cout << "] ";
    }
    cout << endl;

    return 0;
}