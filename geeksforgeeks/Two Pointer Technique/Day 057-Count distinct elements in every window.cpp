/* Que.57) Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array. */


#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
      vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < k; i++){
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        
        for(int i = k; i < arr.size(); i++){
            mp[arr[i]]++;
            int oldElem = arr[i - k];
            
            if(mp[oldElem] == 1){
                mp.erase(oldElem);
            }else{
                mp[oldElem]--;
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {1,2,1,3,4,2,3};
    auto res1 = obj.countDistinct(arr1, 4);
    for(int x : res1) cout << x << " "; // Output: 3 4 4 3
    cout << endl;

    vector<int> arr2 = {4,1,1};
    auto res2 = obj.countDistinct(arr2, 2);
    for(int x : res2) cout << x << " "; // Output: 2 1
    cout << endl;

    vector<int> arr3 = {1,1,1,1,1};
    auto res3 = obj.countDistinct(arr3, 3);
    for(int x : res3) cout << x << " "; // Output: 1 1 1
    cout << endl;

    return 0;
}
