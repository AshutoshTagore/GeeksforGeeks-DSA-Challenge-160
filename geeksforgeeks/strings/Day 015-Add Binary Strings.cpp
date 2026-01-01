/* Que.15) Given two binary strings s1 and s2 consisting of only 0s and 1s. 
Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";

        // Traverse both strings from end to start
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if(i >= 0) {
                sum += s1[i] - '0';
                i--;
            }

            if(j >= 0) {
                sum += s2[j] - '0';
                j--;
            }

            result += (sum % 2) + '0'; // current digit
            carry = sum / 2;           // update carry
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros if any
        int pos = result.find_first_not_of('0');
        if(pos != string::npos)
            return result.substr(pos);
        else
            return "0";
    }
};

int main() {
    Solution obj;

    string s1 = "1101";
    string s2 = "111";
    cout << "Input: " << s1 << " + " << s2 << endl;
    cout << "Output: " << obj.addBinary(s1, s2) << endl; // Output: 10100

    s1 = "00100";
    s2 = "010";
    cout << "Input: " << s1 << " + " << s2 << endl;
    cout << "Output: " << obj.addBinary(s1, s2) << endl; // Output: 110

    s1 = "0";
    s2 = "0";
    cout << "Input: " << s1 << " + " << s2 << endl;
    cout << "Output: " << obj.addBinary(s1, s2) << endl; // Output: 0

    return 0;
}