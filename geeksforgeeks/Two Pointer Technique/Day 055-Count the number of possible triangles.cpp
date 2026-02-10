/* Que.55) Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. A triangle with three given sides is only possible if sum of any two sides is always greater than the third side. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), ans=0;
        for(int i = n-1; i >=2; i--){
            int j = 0,k=i-1;
            while(j<k){
                int twosidesum = arr[j]+arr[k];
                if(twosidesum>arr[i]){
                    ans+=k-j;
                    k--;
                } else j++;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr1 = {4, 6, 3, 7};
    cout << obj.countTriangles(arr1) << endl; // Output: 3

    vector<int> arr2 = {10, 21, 22, 100, 101, 200, 300};
    cout << obj.countTriangles(arr2) << endl; // Output: 6

    vector<int> arr3 = {1, 2, 3};
    cout << obj.countTriangles(arr3) << endl; // Output: 0

    return 0;
}