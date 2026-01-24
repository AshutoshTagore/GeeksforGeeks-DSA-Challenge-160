/* Que.38) Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool matSearch(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = m - 1; // start from top-right corner

        while(i < n && j >= 0) {
            if(mat[i][j] == x) return true;
            else if(mat[i][j] > x) j--;   // move left
            else i++;                     // move down
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat1 = {{3,30,38},{20,52,54},{35,60,69}};
    cout << (obj.matSearch(mat1, 62) ? "true" : "false") << endl; // Output: false

    vector<vector<int>> mat2 = {{18,21,27},{38,55,67}};
    cout << (obj.matSearch(mat2, 55) ? "true" : "false") << endl; // Output: true

    vector<vector<int>> mat3 = {{1,2,3},{4,5,6},{7,8,9}};
    cout << (obj.matSearch(mat3, 3) ? "true" : "false") << endl; // Output: true

    return 0;
}