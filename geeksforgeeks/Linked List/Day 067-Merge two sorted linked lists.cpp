/* Que.67) Given the head of two sorted linked lists consisting of nodes respectively. Merge both lists and return the head of the sorted merged list. */


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
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* dummy = new Node(-1);
        Node* tail = dummy; 
        
        while (head1 != NULL && head2 != NULL) {
            if (head1->data <= head2->data) {
                tail->next = head1; 
                head1 = head1->next; 
            } 
            else {
                tail->next = head2;
                head2 = head2->next; 
            }
            tail = tail->next;
        }
        if (head1 != NULL) {
            tail->next = head1;
        }
        if (head2 != NULL) {
            tail->next = head2;
        }
        
        Node* mergedHead = dummy->next;
        
        delete dummy; 
        
        return mergedHead;
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
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);
    head1->next->next->next = new Node(40);

    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    cout << "List 1: ";
    printList(head1);
    
    cout << "List 2: ";
    printList(head2);

    Solution obj;
    Node* mergedHead = obj.sortedMerge(head1, head2);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}