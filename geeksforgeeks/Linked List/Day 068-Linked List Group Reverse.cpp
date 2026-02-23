/* Que.68) You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list. */


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
    Node *reverseKGroup(Node *head, int k) {
        if (head == NULL) {
            return NULL;
        }

        Node* curr = head;
        Node* next_node = NULL;
        Node* prev = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            count++;
        }

        if (curr != NULL) {
            head->next = reverseKGroup(curr, k); 
        }

        return prev;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 4; 

    cout << "Original List: ";
    printList(head);

    Solution obj;
    Node* newHead = obj.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(newHead);

    return 0;
}