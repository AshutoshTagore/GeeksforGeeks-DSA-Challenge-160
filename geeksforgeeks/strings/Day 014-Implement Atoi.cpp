/* Que.14) Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.
Cases for atoi() conversion:

1)Skip any leading whitespaces.
2)Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
3)Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
4)If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // Skip leading whitespaces
        while(i < n && s[i] == ' ') {
            i++;
        }

        // Check for sign
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        // Read digits and build number
        long long result = 0;
        while(i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Clamp to 32-bit integer limits
            if(sign == 1 && result > INT_MAX) return INT_MAX;
            if(sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        // Return final result
        return static_cast<int>(sign * result);
    }
};

int main() {
    Solution obj;
    cout << obj.myAtoi("-123") << endl;               // Output: -123
    cout << obj.myAtoi("  -") << endl;                // Output: 0
    cout << obj.myAtoi(" 1231231231311133") << endl;  // Output: 2147483647
    cout << obj.myAtoi("-999999999999") << endl;      // Output: -2147483648
    cout << obj.myAtoi("  -0012gfg4") << endl;        // Output: -12
    return 0;
}