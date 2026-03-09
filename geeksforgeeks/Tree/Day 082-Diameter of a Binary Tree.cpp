/* Que.82) Given the root of a binary tree, your task is to find the diameter of the binary tree. */

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

class Solution{
    public:
    int heightAndDiameter(Node* node, int& ans){
        if (node == NULL){
            return 0;
        }
        int lh = heightAndDiameter(node->left, ans);

        int rh = heightAndDiameter(node->right,ans);

        ans = max(ans, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameter(Node* root){
        int ans =0;
        heightAndDiameter(root, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(9);

    Solution obj;
    cout << "Diameter of the tree is: " << obj.diameter(root) << " edges." << endl;

    return 0;
}