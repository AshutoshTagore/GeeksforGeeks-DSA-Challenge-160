/* Que.78) Solve the Sudoku */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool solve(vector<vector<int>>& mat, int r, int c,int rowSafe[9][10], int colSafe[9][10], int boxSafe[9][10]){
        if(r == 9) return true;
        if(c == 9) return solve(mat, r+1, 0, rowSafe, colSafe, boxSafe);
        
        if(mat[r][c] != 0) return solve(mat, r, c + 1, rowSafe, colSafe, boxSafe);
        
        int boxIdx = (r / 3) * 3 + (c / 3);
        
        for(int num = 1; num <=9; num++){
            if(!rowSafe[r][num] && !colSafe[c][num] && !boxSafe[boxIdx][num]){
                mat[r][c] = num;
                rowSafe[r][num] = 1;
                colSafe[c][num] = 1;
                boxSafe[boxIdx][num] = 1;
                
                if(solve(mat, r, c+1, rowSafe, colSafe, boxSafe)){
                    return true;
                }
                mat[r][c]=0;
                rowSafe[r][num] = 0;
                colSafe[c][num] = 0;
                boxSafe[boxIdx][num] = 0;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<int>>& mat) {
        int rowSafe[9][10] = {0};
        int colSafe[9][10] = {0};
        int boxSafe[9][10] = {0};
        
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(mat[i][j] != 0){
                    int num = mat[i][j];
                    int boxIdx =(i / 3) * 3 + (j/3);
                    
                    rowSafe[i][num] = 1;
                    colSafe[j][num] = 1;
                    boxSafe[boxIdx][num] = 1;
                }
            }
        }
        solve(mat, 0, 0, rowSafe, colSafe, boxSafe);
    }
  };