/* Que.63) Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> prefixsum;
        int n = arr.size(), sum=0,ans=0;
        for(int i = 0 ;i<n;i++){
            sum+=arr[i]==1?1:-1;
            if(sum==0){
                ans = i + 1;
            }
            if(prefixsum.find(sum)!=prefixsum.end()){
                ans=max(ans,i-prefixsum[sum]);
            }
            else{
                prefixsum[sum]=i;
            }
        }
        return ans;
    }
};

int main() {
        Solution obj;
        vector<int> arr = {1, 0, 1, 1, 1, 0, 0};
        cout << obj.maxLen(arr) << endl; // Output: 6
        return 0;
}