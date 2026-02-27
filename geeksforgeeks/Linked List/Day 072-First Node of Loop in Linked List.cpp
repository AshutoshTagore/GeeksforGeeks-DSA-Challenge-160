/* Que.72) You are given the head of a singly linked list. If a loop is present in the linked list then return the first node of the loop else return -1. */


#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* findFirstNode(Node* head) {
        if (head == NULL || head->next == NULL) {
            return NULL; 
        }

        Node* slow = head;
        Node* fast = head;
        bool hasLoop = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasLoop = true;
                break; 
            }
        }

        if (!hasLoop) {
            return NULL;
        }

        slow = head; 

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

void createLoop(Node* head, int pos) {
    if (pos == 0) return;
    
    Node* temp = head;
    Node* loopNode = NULL;
    int count = 1;
    
    while (temp->next != NULL) {
        if (count == pos) loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int pos = 3; 
    createLoop(head, pos);

    Solution obj;
    Node* firstNode = obj.findFirstNode(head);

    if (firstNode != NULL) {
        cout << "First node of the loop is: " << firstNode->data << endl; // Output: 3
    } else {
        cout << "No loop exists. Output: -1" << endl;
    }

    return 0;
}