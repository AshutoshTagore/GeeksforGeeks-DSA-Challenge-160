/* Que.27) Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. 
Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.*/


#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int m = b.size();

    int i = n - 1, j = 0;

    // Swap elements if needed
    while(i >= 0 && j < m) {
        if(a[i] > b[j]) {
            swap(a[i], b[j]);
        }
        i--;
        j++;
    }

    // Sort both arrays again
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};

    mergeArrays(a, b);

    cout << "a[] = ";
    for(int x : a) cout << x << " ";
    cout << "\nb[] = ";
    for(int x : b) cout << x << " ";
    cout << endl;

    // Output:
    // a[] = 1 2 3 5 8 9
    // b[] = 10 13 15 20
}

