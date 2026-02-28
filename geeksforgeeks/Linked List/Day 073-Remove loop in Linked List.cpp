/* Que.73) Remove loop in Linked List */

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node* next;
  
      Node(int val) {
          data = val;
          next = nullptr;
      }
};


class Solution {
    public:
      void removeLoop(Node* head) {
          if (head == NULL || head->next == NULL){
              return;
          }
          
          Node* slow = head;
          Node* fast = head;
          bool isCycle = false;
          
          while(fast != NULL && fast->next != NULL){
              slow = slow->next;
              fast = fast->next->next;
              
              if(slow == fast){
                  isCycle = true;
                  break;
              }
          }
          
          if(!isCycle){
              return;
          }
          
          slow = head;
          
          if (slow == fast) {
              while (fast->next != slow) {
                  fast = fast->next;
              }
              fast->next = NULL;
          } 
          else {
              Node* prev = NULL;
              while(slow != fast){
                  prev = fast;
                  slow = slow->next;
                  fast = fast->next;
              }
              prev->next = NULL; 
          }
      }
  };