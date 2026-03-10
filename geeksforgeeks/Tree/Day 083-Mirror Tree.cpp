/* Que.83) Given the root of a binary tree, convert the binary tree to its Mirror tree. */

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
    public:
      void mirror(Node* node) {
          if (node == NULL) {
              return;
          }
          
          mirror(node->left);
          
          mirror(node->right);
          
          Node* temp = node->left;
          node->left = node->right;
          node->right = temp;
      }
  };