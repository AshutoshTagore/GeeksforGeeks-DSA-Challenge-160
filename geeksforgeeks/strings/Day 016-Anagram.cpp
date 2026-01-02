/* Que.16) Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAnagrams(string s1, string s2) {
        if(s1.size() != s2.size()) return false;

        vector<int> freq(26, 0);

        for(char c : s1) {
            freq[c - 'a']++;
        }

        for(char c : s2) {
            freq[c - 'a']--;
        }

        for(int count : freq) {
            if(count != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution obj;
    cout << obj.areAnagrams("geeks", "kseeg") << endl;     // Output: 1 (true)
    cout << obj.areAnagrams("allergy", "allergyy") << endl; // Output: 0 (false)
    cout << obj.areAnagrams("listen", "lists") << endl;     // Output: 0 (false)
    return 0;
}