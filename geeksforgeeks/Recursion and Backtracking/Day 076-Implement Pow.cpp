/* Que.76) Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).  */


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double power(double b, int e){
        long binForm = e;
        double ans = 1;

        if(e == 0) return 1.0;
        if(b == 0) return 0.0;
        if(b == 1) return 1.0;
        if(b == -1 && e%2 == 0) return 1.0;
        if(b == -1 && e%2 !=0) return -1.0;

        if(e < 0){
            b = 1/b;
            binForm = -binForm;
        }

        while(binForm > 0){
            if(binForm%2 == 1){
                ans *=b;
            }
            b*=b;
            binForm/=2;
        }
        return ans;
    }
};


int main() {
    Solution obj;
    
    double b1 = 3.00000;
    int e1 = 5;
    cout << "Test Case 1:" << endl;
    cout << "Input: b = " << b1 << ", e = " << e1 << endl;
    cout << "Output: " << fixed << setprecision(5) << obj.power(b1, e1) << endl << endl;
    
    double b2 = 0.55000;
    int e2 = 3;
    cout << "Test Case 2:" << endl;
    cout << "Input: b = " << b2 << ", e = " << e2 << endl;
    cout << "Output: " << fixed << setprecision(5) << obj.power(b2, e2) << endl << endl;
    
    double b3 = -0.67000;
    int e3 = -7;
    cout << "Test Case 3:" << endl;
    cout << "Input: b = " << b3 << ", e = " << e3 << endl;
    cout << "Output: " << fixed << setprecision(5) << obj.power(b3, e3) << endl << endl;
    
    return 0;
}
