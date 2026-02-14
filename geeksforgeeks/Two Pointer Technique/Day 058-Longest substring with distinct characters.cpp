/* Que.58) You are given a string s. You have to find the length of the longest substring with all distinct characters.  */


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        vector<int> freq(26, 0); 
        
        int n = s.size();
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            int currentCharIndex = s[right] - 'a';

            freq[currentCharIndex]++;

            while (freq[currentCharIndex] > 1) {
                int leftCharIndex = s[left] - 'a';
                freq[leftCharIndex]--; 
                left++; 
            }

            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

int main() {
    Solution obj;
    string s = "geeksforgeeks";
    cout << obj.longestUniqueSubstr(s) << endl; // Output: 7 ("eksforg")
    return 0;
}