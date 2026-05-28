#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buyPrice = prices[0];
    int profit  = 0;

    for(int idx = 1; idx < n; idx++) { 
        if(buyPrice > prices[idx]) {
            buyPrice = prices[idx];
        }
        profit = max(profit, prices[idx] - buyPrice);
    }

    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<"the  Max profit is = " << maxProfit(prices)<<endl;
    return 0;
}