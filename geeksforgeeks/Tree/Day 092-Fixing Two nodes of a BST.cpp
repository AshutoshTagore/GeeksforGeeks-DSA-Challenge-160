/* Que.92) Given the root of a Binary Search Tree (BST), where exactly two nodes were swapped by mistake, your task is to fix (or correct) the BST by swapping them back. The structure of the tree should not change.  */


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
    Node* first = nullptr, *second = nullptr, *prev = nullptr;
    void inorder (Node* root) {
        if(!root) return;
        inorder (root->left);
        if(prev && root->data < prev->data) {
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        inorder (root->right);
    }
    void correctBST (Node* root) {
        inorder(root);
        if(first && second) swap(first->data, second->data);
    }
};