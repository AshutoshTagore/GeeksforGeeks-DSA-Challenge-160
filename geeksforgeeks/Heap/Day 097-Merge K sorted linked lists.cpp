/* Que.97) Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list. */

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
    struct compare{
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
      Node* mergeKLists(vector<Node*>& arr) {
          priority_queue<Node*, vector<Node*>, compare> minHeap;
          for(auto l:arr){
              if(l) minHeap.push(l);
          }
          Node* dummy = new Node(-1);
          Node* tail = dummy;
          
          while(!minHeap.empty()){
              Node* temp = minHeap.top();
              minHeap.pop();
              
              tail->next = temp;
              tail=temp;
              
              if(temp->next){
                  minHeap.push(temp->next);
              }
          }
          return dummy->next;
      }
  };