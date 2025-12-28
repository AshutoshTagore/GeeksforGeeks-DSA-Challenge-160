/* Que.8) Given an array prices[] of length n, representing the prices of the stocks on different days. 
The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. 
Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.*/


#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int min_price = INT_MAX;   
    int maxprofit = 0;        

    for(int i = 0; i < prices.size(); i++) {
       
        if(prices[i] < min_price) {
            min_price = prices[i];
        }
       
        else if(prices[i] - min_price > maxprofit) {
            maxprofit = prices[i] - min_price;
        }
    }
    return maxprofit;
}

int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << maximumProfit(prices) << endl; // Output: 8
    return 0;
}