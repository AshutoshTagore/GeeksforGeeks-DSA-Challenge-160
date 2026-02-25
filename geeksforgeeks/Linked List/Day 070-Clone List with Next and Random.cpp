/* Que.70) Clone List with Next and Random */


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *cloneLinkedList(Node *head) {
        if (head == NULL) return NULL;

        Node* curr = head;
        while (curr != NULL) {
            Node* temp = curr->next;
            Node* copyNode = new Node(curr->data); 
            
            curr->next = copyNode; 
            copyNode->next = temp; 
            curr = temp; 
        }

        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; 
        }

        curr = head;
        Node* copyHead = head->next; 
        Node* copyCurr = copyHead;

        while (curr != NULL) {
            curr->next = curr->next->next; 
            if (copyCurr->next != NULL) {
                copyCurr->next = copyCurr->next->next;
            }
            
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << "[Data: " << head->data;
        if (head->random) cout << ", Random: " << head->random->data << "] -> ";
        else cout << ", Random: NULL] -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next; 
    head->next->random = head;      
    head->next->next->random = head->next; 

    cout << "Original List: " << endl;
    printList(head);

    Solution obj;
    Node* clonedHead = obj.cloneLinkedList(head);

    cout << "\nCloned List: " << endl;
    printList(clonedHead);

    return 0;
}