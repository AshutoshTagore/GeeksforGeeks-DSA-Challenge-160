/* Que.77) N-Queen Problem */


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      bool canPut(int row,int col,vector<int>& temp){
          for(int r =0; r<row; r++){
              if(temp[r] == col + 1){
                  return false;
              }
          }
          int r = row, c = col;
          while(r>=0 and  c>=0){
              if(temp[r]==c+1)return false;
              r--;
              c--;
          }
          r = row, c = col;
          while(r>=0 and c<temp.size()){
              if(temp[r]==c+1) return false;
              r--;
              c++;
          }
          return true;
      }
      void help(int n,vector<vector<int>> &ans,vector<int>& temp,int row){
          if(row==n){
              ans.push_back(temp);
              return;
          }
          for(int col=0;col<n;col++){
              if (canPut(row,col,temp)){
                  temp[row]=col+1;
                  help(n,ans,temp,row+1);
                  temp[row]=0;
              }
          }
      }
      vector<vector<int>> nQueen(int n){
          vector<vector<int>> ans;
          vector<int> temp(n,0);
          help(n,ans,temp,0);
          return ans;
      }
  };