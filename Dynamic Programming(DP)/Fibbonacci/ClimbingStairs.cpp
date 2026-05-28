#include<iostream>
#include<vector>
using namespace std;

int climbingStairsWaysRec(int n){// o(2^n) time complexity
    if(n==1 || n==0){
        return 1;
    }
    return climbingStairsWaysRec(n-1) + climbingStairsWaysRec(n-2);
}

int countWaysMen(int n, vector<int> dp){ /// o(n) time complexity is better
   if(n==0 || n==1){
    return 1;
   }
   if(dp[n] != -1){ // Skip if already calculated
    return dp[n];

   }
   dp[n] = countWaysMen(n-1, dp) + countWaysMen(n-2, dp);
   return dp[n];
}
int countWaysTab(int n){
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n=3;
    vector<int> dp(n+1, -1);
    cout << climbingStairsWaysRec(n) << endl;
    cout << countWaysMen(n,dp) << endl;
    cout << countWaysTab(n) << endl;
    return 0;
}