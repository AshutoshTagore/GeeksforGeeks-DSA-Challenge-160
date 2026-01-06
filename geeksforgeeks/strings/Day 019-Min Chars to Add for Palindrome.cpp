/* Que.19) Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.
Note: A palindrome string is a sequence of characters that reads the same forward and backward.*/

#include <bits/stdc++.h>
using namespace std;

int minChar(string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string pat = s + "|" + rev;
    int k = pat.size();
    vector<int> lps(k, 0);

    for (int i = 1, len = 0; i < k;) {
        if (pat[i] == pat[len]){
            lps[i++] = ++len;
        } else if(len){
            len = lps[len-1];
        } else{
            lps[i++]=0;
        }
    }

    return s.size() - lps[k - 1];
}

int main() {
    string s = "abc";
    cout << minChar(s) << "\n";   // output: 2 for "abc"
    return 0;
}