/* Que.91) Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target.  */

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
    void inorder (Node* root, vector<int>& val) {
        if(!root) return;
        inorder(root->left, val);
        val.push_back(root->data);
        inorder (root->right, val);
    }
    bool checkPair(vector<int> val, int target){
        int left=0, right=val.size()-1;
        while(left<right) {
            int sum = val [left]+val [right];
            if(sum==target) return true;
            (sum<target)? left++ : right--;
        }
        return false;
    }
    bool findTarget (Node* root, int target) {
        vector<int> val;
        inorder (root, val);
        return checkPair(val, target);
    }
};