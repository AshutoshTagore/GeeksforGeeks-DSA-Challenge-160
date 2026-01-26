/* Que.40) Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n*m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if(mat[row][col] == x) return true;
            else if(mat[row][col] < x) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat1 = {{1,5,9},{14,20,21},{30,34,43}};
    cout << (obj.searchMatrix(mat1, 14) ? "true" : "false") << endl; // true

    vector<vector<int>> mat2 = {{1,5,9,11},{14,20,21,26},{30,34,43,50}};
    cout << (obj.searchMatrix(mat2, 42) ? "true" : "false") << endl; // false

    vector<vector<int>> mat3 = {{87,96,99},{101,103,111}};
    cout << (obj.searchMatrix(mat3, 101) ? "true" : "false") << endl; // true

    return 0;
}