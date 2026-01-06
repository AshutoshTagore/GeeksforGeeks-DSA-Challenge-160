/* Que.18) Given two strings, one is a text string txt and the other is a pattern string pat. 
The task is to print the indexes of all the occurrences of the pattern string in the text string. 
Use 0-based indexing while returning the indices.
Note: Return an empty list in case of no occurrences of pattern.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        vector<int> result;
        int n = txt.size(), m = pat.size();

        // Build LPS array
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while(i < m) {
            if(pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Pattern matching
        i = 0;
        int j = 0;
        while(i < n) {
            if(txt[i] == pat[j]) {
                i++; j++;
            }

            if(j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if(i < n && txt[i] != pat[j]) {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};

int main() {
    string txt = "abcab", pat = "ab";
    Solution obj;
    vector<int> ans = obj.search(pat, txt);
    for (int idx : ans) cout << idx << " ";  // Output: 0 3
    return 0;
}
