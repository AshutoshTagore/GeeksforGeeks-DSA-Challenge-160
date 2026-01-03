/* Que.17) Given a string s consisting of lowercase English Letters. 
return the first non-repeating character in s. 
If there is no non-repeating character, return '$'.*/



#include <bits/stdc++.h>  
using namespace std;

int nonRepeatingChar(string s){
    vector<int> freq(26, 0);

    //Count frequency of each character
    for(char c : s){
        freq[c - 'a']++;
    }

    //Find first character with frequency = 1
    for(char c : s){
        if(freq[c - 'a'] == 1){
            return c;
        }
    }

    //If none found, return '$'
        return '$';

}

int main(){
    string s = "geeksforgeeks";

    char result = nonRepeatingChar(s);

    cout << result << endl; //Output: f
    return 0;
}