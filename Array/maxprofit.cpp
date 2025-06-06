#include<iostream>
using namespace std;
int maxprofit(int prices[], int n){
    int minprices = prices[0];
    int profit = 0;
    for(int i=0; i<n; i++){
        if(prices < minprices){
            minprices = prices[i];
        }
        else{
            int profit = prices[0] - minprices;
        }
        if(profit>maxprofit){
            maxprofit = profit;

        }
    }
    return maxprofit;
}
int main(){
    int arr[6] = {7,1,5,3,6,4,2};
    int n = sizeof(prices)/sizeof(profit[0]);
    int profit = maxprofit(prices, n);
    cout<<"Maximum profit is:"<<profit<<endl;
    return 0;
}
