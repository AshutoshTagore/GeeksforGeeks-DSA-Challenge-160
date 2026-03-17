/* Que.90) Given the root of a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1. */

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
    void findKth(Node* root, int k, int& count, int& ans){
        if(root == NULL || count >= k){
            return;
        }
        findKth(root->left, k, count, ans);
        
        count++;
        if(count == k){
        ans = root->data;
        return;
    }

    findKth(root->right, k, count, ans);
    }
    int kthSmallest(Node *root, int k) {
        int count = 0;
        int ans = -1;
          
        findKth(root, k, count, ans);
          
        return ans;
          
    }
};