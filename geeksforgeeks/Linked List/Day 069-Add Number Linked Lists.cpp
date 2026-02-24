/* Que.69) You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You have to return the head of the linked list representing the sum of these two numbers. */


#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  private:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    Node* trimLeadingZeros(Node* head) {
        while (head != NULL && head->data == 0 && head->next != NULL) {
            head = head->next;
        }
        return head;
    }

  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = trimLeadingZeros(num1);
        num2 = trimLeadingZeros(num2);

        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node* res = NULL; 
        int carry = 0;

        while (num1 != NULL || num2 != NULL || carry > 0) {
            int sum = carry;

            if (num1 != NULL) {
                sum += num1->data;
                num1 = num1->next;
            }

            if (num2 != NULL) {
                sum += num2->data;
                num2 = num2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            Node* newNode = new Node(digit);
            newNode->next = res;
            res = newNode;
        }

        return res;
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
    Node* head1 = new Node(0);
    head1->next = new Node(1);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(3);

    Node* head2 = new Node(0);
    head2->next = new Node(0);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(9);
    head2->next->next->next->next = new Node(9);

    cout << "Number 1: ";
    printList(head1);
    cout << "Number 2: ";
    printList(head2);

    Solution obj;
    Node* result = obj.addTwoLists(head1, head2);

    cout << "Sum:      ";
    printList(result); 

    return 0;
}