/* Que.85) Given a root of a Binary Tree, your task is to return its Inorder Traversal. */


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
    void solve(Node* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        
        solve(root->left, ans);
        
        ans.push_back(root->data);
        
        solve(root->right, ans);
    }

  public:
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution obj;
    vector<int> result = obj.inOrder(root);

    cout << "Inorder Traversal: [";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}