/* Que.32) Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();

        // Ensure a is smaller
        if(n > m) return kthElement(b, a, k);

        int low = max(0, k - m), high = min(k, n);

        while(low <= high) {
            int cutA = (low + high) / 2;
            int cutB = k - cutA;

            int leftA = (cutA == 0) ? INT_MIN : a[cutA - 1];
            int leftB = (cutB == 0) ? INT_MIN : b[cutB - 1];
            int rightA = (cutA == n) ? INT_MAX : a[cutA];
            int rightB = (cutB == m) ? INT_MAX : b[cutB];

            if(leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB);
            } else if(leftA > rightB) {
                high = cutA - 1;
            } else {
                low = cutA + 1;
            }
        }
        return -1; // should never reach here
    }
};

int main() {
    Solution obj;

    vector<int> a1 = {2,3,6,7,9};
    vector<int> b1 = {1,4,8,10};
    cout << obj.kthElement(a1, b1, 5) << endl; // Output: 6

    vector<int> a2 = {1,4,8,10,12};
    vector<int> b2 = {5,7,11,15,17};
    cout << obj.kthElement(a2, b2, 6) << endl; // Output: 10

    return 0;
}