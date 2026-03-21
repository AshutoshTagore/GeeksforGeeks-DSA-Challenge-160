/* Que.94) Serialize and deserialize a binary tree  */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
  vector<int>result;
  void help(Node* root){
      if(root==nullptr){
          result.push_back(-1);
          return;
      }
      result.push_back(root->data);
      serialize(root->left);
      serialize(root->right);
  }
    vector<int> serialize(Node *root) {
     help(root);
     return result;
    }
    
    int i=0;
    Node *deSerialize(vector<int> &arr) {
        int value = arr[i];
        i++;
        if(value==-1){
            return NULL;
        }
        Node* newNode = new Node(value);
        newNode->left = deSerialize(arr);
        newNode->right = deSerialize(arr);
        return newNode;
    }
};