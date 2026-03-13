/* Que.86) Given a binary tree, the task is to return a list of nodes representing its boundary traversal in an anticlockwise direction, starting from the root. */

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
    bool isLeaf(Node* root){
        return(root->left == NULL && root->right == NULL);
    }
    void addLB(Node* root, vector<int>& ans){
        Node* curr = root->left;
        while (curr != NULL){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left!=NULL){
                curr=curr->left;
            } else{
                curr=curr->right;
            }
        }
    }

    void addLeaves(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRB(Node* root, vector<int> ans){
        Node* curr = root->right;
        vector<int> temp;

        while(curr!=NULL){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right != NULL){
                curr = curr->right;
            } else{
                curr = curr->left;
            }
        }
        for(int i = temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }

    public:
    vector<int> boundaryTraversal(Node *root){
        vector<int> ans;

        if(root == NULL){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        addLB(root, ans);
        addLeaves(root, ans);
        addRB(root, ans);

        return ans;
    }
};