#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size();
    int stocks = prices[0];
    int profit = 0;

    for(int i=0; i<n; i++){
        profit = max(profit, prices[i]-stocks);
        stocks = min(stocks, prices[i]);
    }
    return profit;
}

int main(){
    vector<int> prices = {7,1,5,3,6,4};

    cout << " max profit : "<< maxProfit(prices) << endl;
    return 0;

}