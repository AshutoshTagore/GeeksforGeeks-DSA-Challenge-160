/* Que.41) You are given a 2D matrix mat[][] of size n x m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0. */



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool firstRowZero = false, firstColZero = false;


        for(int j = 0; j < m; j++)
            if(mat[0][j] == 0) firstRowZero = true;


        for(int i = 0; i < n; i++)
            if(mat[i][0] == 0) firstColZero = true;


        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        }

        if(firstRowZero) {
            for(int j = 0; j < m; j++)
                mat[0][j] = 0;
        }

        if(firstColZero) {
            for(int i = 0; i < n; i++)
                mat[i][0] = 0;
        }
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {1, -1, 1},
        {-1, 0, 1},
        {1, -1, 1}
    };

    cout << "Original Matrix:\n";
    for(auto row : mat) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    obj.setMatrixZeroes(mat);

    cout << "\nModified Matrix:\n";
    for(auto row : mat) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
