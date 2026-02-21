/* Que.66) You are given the head of a singly linked list, you have to left rotate the linked list k times. Return the head of the modified linked list. */

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
    Node* rotate(Node* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        Node* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        
        if (k == 0) {
            return head;
        }

        tail->next = head;

        Node* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        Node* newHead = curr->next;  
        curr->next = NULL;        

        return newHead;
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
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    int k = 4;

    cout << "Original List: ";
    printList(head);
    cout << "Rotating left by " << k << " places..." << endl;

    Solution obj;
    Node* rotatedHead = obj.rotate(head, k);

    cout << "Rotated List:  ";
    printList(rotatedHead);

    return 0;
}