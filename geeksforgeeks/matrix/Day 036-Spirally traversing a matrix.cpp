/* Que.36) You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form. */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> result;

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        while(top <= bottom && left <= right) {
            // Traverse Left to Right
            for(int i = left; i <= right; i++)
                result.push_back(mat[top][i]);
            top++;

            // Traverse Top to Bottom
            for(int i = top; i <= bottom; i++)
                result.push_back(mat[i][right]);
            right--;

            // Traverse Right to Left
            if(top <= bottom) {
                for(int i = right; i >= left; i--)
                    result.push_back(mat[bottom][i]);
                bottom--;
            }

            // Traverse Bottom to Top
            if(left <= right) {
                for(int i = bottom; i >= top; i--)
                    result.push_back(mat[i][left]);
                left++;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> res1 = obj.spirallyTraverse(mat1);
    cout << "Spiral Traversal of mat1: ";
    for(int x : res1) cout << x << " ";
    cout << endl;

    vector<vector<int>> mat2 = {
        {32, 44, 27, 23},
        {54, 28, 50, 62}
    };

    vector<int> res2 = obj.spirallyTraverse(mat2);
    cout << "Spiral Traversal of mat2: ";
    for(int x : res2) cout << x << " ";
    cout << endl;

    return 0;
}