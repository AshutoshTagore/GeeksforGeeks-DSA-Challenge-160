/* Que.80) Given the root of a binary tree with n nodes, the task is to find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree, where we visit nodes level by level. */


#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> currentLevel;
            
            for(int i = 0;i < size; i++){
                Node* temp = q.front();
                q.pop();
                
                currentLevel.push_back(temp->data);
                if (temp->left != NULL){
                    q.push(temp->left);
                }
                if (temp->right != NULL){
                    q.push(temp->right);
                }
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }
};

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    Solution obj;
    vector<vector<int>> result = obj.levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Level " << i + 1 << ": [";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}