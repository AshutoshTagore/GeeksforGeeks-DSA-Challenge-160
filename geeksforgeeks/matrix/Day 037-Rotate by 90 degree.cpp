/* Que.37) Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // Reverse each column
        for(int j = 0; j < n; j++) {
            int top = 0, bottom = n-1;
            while(top < bottom) {
                swap(mat[top][j], mat[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };

    obj.rotateMatrix(mat);

    cout << "Rotated Matrix:\n";
    for(auto row : mat) {
        for(auto x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}