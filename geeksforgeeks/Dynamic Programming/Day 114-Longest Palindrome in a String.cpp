/* Longest Palindrome in a String */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int maxLen = 1;
        int start = 0;
        int n = s.length();
        
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currentLen = right - left + 1;
                
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                left--;
                right++;
            }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);   
            expand(i, i + 1);   
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Solution sol;
    cout << "Length of longest palindrome: " << sol.longestPalindrome(s) << endl;
    return 0;
}