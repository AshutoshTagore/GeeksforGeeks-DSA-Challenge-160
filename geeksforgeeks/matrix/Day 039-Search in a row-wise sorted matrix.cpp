/* Que.39) Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1]. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++) {
            // Binary search in row i
            int low = 0, high = m - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(mat[i][mid] == x) return true;
                else if(mat[i][mid] < x) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat1 = {{3,4,9},{2,5,6},{9,25,27}};
    cout << (obj.searchMatrix(mat1, 9) ? "true" : "false") << endl; // Output: true

    vector<vector<int>> mat2 = {{19,22,27,38,55,67}};
    cout << (obj.searchMatrix(mat2, 56) ? "true" : "false") << endl; // Output: false

    vector<vector<int>> mat3 = {{1,2,9},{65,69,75}};
    cout << (obj.searchMatrix(mat3, 91) ? "true" : "false") << endl; // Output: false

    return 0;
}