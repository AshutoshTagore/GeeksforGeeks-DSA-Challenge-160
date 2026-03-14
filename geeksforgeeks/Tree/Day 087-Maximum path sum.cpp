/* Que.87) Given the root of a binary tree, your task is to find the maximum path sum. The path may start and end at any node in the tree. */


#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    int maxPathDown(Node* node, int& maxi) {
        if (node == NULL) {
            return 0;
        }
        int leftSum = max(0, maxPathDown(node->left, maxi));
        
        int rightSum = max(0, maxPathDown(node->right, maxi));
        
        maxi = max(maxi, node->data + leftSum + rightSum);
        
        return node->data + max(leftSum, rightSum);
    }

  public:
    int findMaxSum(Node* root) {
        int maxi = INT_MIN; 
        
        maxPathDown(root, maxi);
        
        return maxi;
    }
};