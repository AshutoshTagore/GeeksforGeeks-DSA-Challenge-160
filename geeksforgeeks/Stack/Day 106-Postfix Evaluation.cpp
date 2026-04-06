/* Que.106) Postfix Evaluation */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for (string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^") {
                int op2 = st.top(); 
                st.pop();
                
                int op1 = st.top(); 
                st.pop();
                
                if (token == "+") {
                    st.push(op1 + op2);
                } 
                else if (token == "-") {
                    st.push(op1 - op2);
                } 
                else if (token == "*") {
                    st.push(op1 * op2);
                } 
                else if (token == "/") {
                    st.push(floor((double)op1 / op2));
                } 
                else if (token == "^") {
                    st.push(pow(op1, op2));
                }
            } 
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};