/* Que.20) You are given two strings s1 and s2, of equal lengths.
The task is to check if s2 is a rotated version of the string s1.
Note: A string is a rotation of another if it can be formed by moving characters from the start to the end (or vice versa) without rearranging them.*/


#include <bits/stdc++.h>
using namespace std;

bool areRotations(string &s1, string &s2) {
    if (s1.size() != s2.size()) return false;
    string pat = s2;
    string txt = s1 + s1;
    int k = pat.size();
    vector<int> lps(k, 0);
    
    // Compute LPS array
    for (int i = 1, len = 0; i < k; ) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    
    // KMP search
    for (int i = 0, j = 0; i < txt.size(); ) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == k) {
                return true;
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    string s1 = "abcde";
    string s2 = "cdeab";
    if (areRotations(s1, s2))
        cout << "Yes, rotation\n";
    else
        cout << "No, not rotation\n";
    return 0;
}
