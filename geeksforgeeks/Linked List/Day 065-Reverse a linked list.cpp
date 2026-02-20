/* Que.65) You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list. */


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
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next_node = NULL;
        
        while (curr != NULL) {
            next_node = curr->next;
            curr->next = prev;
            prev = curr;     
            curr = next_node;  
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    Solution obj;
    Node* reversedHead = obj.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}