/* Que.81) Given the root of a binary tree, your task is to find the maximum depth of the tree. */


#include <bits/stdc++.h>
using namespace std;

// Node structure
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
    int height(Node* node) {
        if (node == NULL) {
            return -1;
        }
        int leftHeight = height(node->left);
        
        int rightHeight = height(node->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    Node* root = new Node(12);
    root->left = new Node(8);
    root->right = new Node(18);
    root->left->left = new Node(5);
    root->left->right = new Node(11);

    Solution obj;
    cout << "Height of the tree (Number of edges): " << obj.height(root) << endl;

    return 0;
}