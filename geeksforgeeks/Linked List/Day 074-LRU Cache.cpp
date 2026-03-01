/* Que.74) LRU Cache */


#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    public:
    class Node{
        public:
        int key, val;
        Node* prev;
        Node* next;
        
        Node(int k, int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int limit;
    
    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }
    
    void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
    
      LRUCache(int cap) {
          limit = cap;
          head->next = tail;
          tail->prev = head;
      
      }
  
      int get(int key){
          if(m.find(key) == m.end()){
              return -1;
          }
          Node* ansNode = m[key];
          int ans = ansNode->val;
          delNode(ansNode);
          addNode(ansNode);
          m[key] = ansNode;
          return ans;
      }
  
          
      void put(int key, int value) {
          if(m.find(key) != m.end()){
              Node* oldNode = m[key];
              delNode(oldNode);
              m.erase(key);
          }
          if(m.size()==limit){
              m.erase(tail->prev->key);
              delNode(tail->prev);
          }
          Node* newNode = new Node(key, value);
          addNode(newNode);
          m[key]=newNode;
      }
  };



  int main() {
    cout << "Testing LRU Cache with Capacity 2..." << endl;

    LRUCache cache(2);

    cout << "PUT(1, 2)" << endl;
    cache.put(1, 2);
    
    cout << "PUT(2, 3)" << endl;
    cache.put(2, 3);
    
    cout << "PUT(1, 5) -> Updates key 1" << endl;
    cache.put(1, 5);
    
    cout << "PUT(4, 5) -> Cache full, evicts key 2" << endl;
    cache.put(4, 5);
    
    cout << "PUT(6, 7) -> Cache full, evicts key 1" << endl;
    cache.put(6, 7);
    
    cout << "GET(4)    -> Returned: " << cache.get(4) << " (Expected: 5)" << endl;
    
    cout << "PUT(1, 2) -> Cache full, evicts key 6" << endl;
    cache.put(1, 2);
    
    cout << "GET(3)    -> Returned: " << cache.get(3) << " (Expected: -1)" << endl;

    return 0;
}