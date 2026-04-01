/* Que.105) Get Min from Stack */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    stack<pair<int, int>> st;

    void push(int x) {
        if (st.empty()) {
            st.push({x, x});
        } else {
            int current_min = min(x, st.top().second);
            st.push({x, current_min});
        }
    }
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int peek() {
        if (st.empty()) {
            return -1;
        }
        return st.top().first;
    }

    int getMin() {
        if (st.empty()) {
            return -1;
        }
        return st.top().second;
    }
    bool isEmpty() {
        return st.empty();
    }
};