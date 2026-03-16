/* Que.89) Given the root of a binary tree, check whether it is a Binary Search Tree (BST) or not. */


#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
  bool checkBST(Node* root, int min_val , int max_val){
      if(root == NULL){
          return true;
      }
      if(root->data <= min_val || root->data >= max_val){
          return false;
      }
      bool isLeftValid = checkBST(root->left, min_val , root->data);
      
      bool isRightValid = checkBST(root->right, root->data, max_val);
      
      return isLeftValid && isRightValid;
  }
  
    bool isBST(Node* root) {
        return checkBST(root, INT_MIN, INT_MAX);
        
    }
};