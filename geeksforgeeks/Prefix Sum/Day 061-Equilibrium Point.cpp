/* Que.61) Given an array of integers arr[], the task is to find the first equilibrium point in the array.  */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int findEquilibrium(vector<int> &arr) {
    int n = arr.size(), right = 0, left = 0;
    for(int x:arr) right+=x;
    for(int i=0;i<n;i++){
        right-=arr[i];
        if(left==right) return i;
        left+=arr[i];
    }
    return -1;
}
};

int main() {
    Solution obj;
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    cout << "Equilibrium Point: " << obj.findEquilibrium(arr) << endl; // Output: 3
    return 0;
}