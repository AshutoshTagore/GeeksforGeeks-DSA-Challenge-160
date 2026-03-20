/* Que.93) Lowest Common Ancestor in a BST  */


#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          while (root!=NULL){
            if(root->data > n1->data && root->data > n2->data){
                root = root->left;
            }
            else if (root->data < n1->data && root->data < n2->data){
                root = root->right;
            }
            else{
                return root;
            }
          }
          return NULL;  
      }
  };