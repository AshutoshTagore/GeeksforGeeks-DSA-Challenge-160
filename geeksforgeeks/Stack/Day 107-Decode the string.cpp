/* Que.107) Decode the string */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string decodedString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        
        int currNum = 0;
        string currStr = "";    
        
        for (char c : s) {
            if (isdigit(c)) {
                currNum = (currNum * 10) + (c - '0');
            } 
            else if (c == '[') {
                numStack.push(currNum);
                strStack.push(currStr);
                
                currNum = 0;
                currStr = "";
            }
            else if (c == ']') {
                int k = numStack.top();
                numStack.pop();
                
                string prevStr = strStack.top();
                strStack.pop();
                
                string temp = "";
                for (int i = 0; i < k; i++) {
                    temp += currStr;
                }
                currStr = prevStr + temp;
            }
            else {
                currStr += c;
            }
        }
        return currStr;
    }
};