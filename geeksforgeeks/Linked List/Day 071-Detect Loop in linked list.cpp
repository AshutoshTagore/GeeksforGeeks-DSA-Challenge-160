/* Que.71) Detect Loop in linked list */


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
        bool detectLoop(Node* head) {
            Node *slow = head, *fast = head;
            while (fast && fast->next) {
                if ((slow = slow->next) == (fast = fast->next->next))
                    return true;
            }
            return false;
        }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    int pos = 2;

    Solution obj;
    if (obj.detectLoop(head)) {
        cout << "True: Loop is present in the linked list." << endl;
    } else {
        cout << "False: No loop found." << endl;
    }

    return 0;
}