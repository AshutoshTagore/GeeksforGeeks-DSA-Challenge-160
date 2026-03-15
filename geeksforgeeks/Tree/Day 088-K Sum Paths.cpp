/* Que.88) Given the root of a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. */


#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  void solve(Node* root, int k, int current_sum, unordered_map<int, int>& prefixMap, int& count){
      if(root == NULL) return;
      
      current_sum += root->data;
      
      if(prefixMap.find(current_sum - k) != prefixMap.end()){
          count += prefixMap[current_sum - k];
      }
      prefixMap[current_sum]++;
      
      solve(root->left, k, current_sum, prefixMap, count);
      solve(root->right, k, current_sum, prefixMap, count);
      
      prefixMap[current_sum]--;
  }
  
    int countAllPaths(Node *root, int k) {
        unordered_map<int, int> prefixMap;
        
        prefixMap[0] = 1;
        int count = 0;
        solve(root, k, 0, prefixMap, count);
        
        return count;
        
    }
};