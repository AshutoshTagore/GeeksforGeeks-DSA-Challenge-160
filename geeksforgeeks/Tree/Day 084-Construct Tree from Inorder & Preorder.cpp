/* Que.84) Given two arrays representing the inorder and preorder traversals of a binary tree, your task is to construct the binary tree and return its root. */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
  int search(vector<int>& inorder, int left, int right, int val){
      for (int i = left; i<=right; i++){
          if(inorder[i] == val){
              return i;
          }
      }
      return -1;
  }
  Node *helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
      if(left > right){
          return NULL;
      }
      Node* root = new Node(preorder[preIdx]);
      
      int inIdx = search(inorder, left, right, preorder[preIdx]);
      preIdx++;
      
      root -> left = helper(preorder, inorder, preIdx, left, inIdx-1);
      root -> right = helper(preorder, inorder, preIdx, inIdx+1, right);
      
      return root;
  }
  
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
        
    }
};