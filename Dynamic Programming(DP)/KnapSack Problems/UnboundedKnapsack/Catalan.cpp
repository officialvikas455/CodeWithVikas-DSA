#include<iostream>
#include<vector>
#include<string>
using namespace std;

int catalanRec(int n){
    // base case 
     if(n==0 || n==1){
        return 1;
     }
     int ans=0;
     for(int i=0; i<n; i++){
        ans += catalanRec(i) * catalanRec(n-i-1);
     }
     return ans;
}
int catalanMem(int n, vector<int> &dp){
    // base case 
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n] != -1){ // if already calculated value
        return dp[n];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans += catalanMem(i,dp) * catalanMem(n-i-1,dp);
    }
    return dp[n] = ans;
}
int catalanTab(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1] =1;

    for(int i=2; i<n; i++){
        for(int j=0; j<i; j++){
            dp[n] = catalanTab(j)*catalanTab(j-i-1);
        }
    }
    return dp[n];
}
int main(){
    int n=6;
    vector<int> dp(n+1,-1);

    for(int i=0; i<=n; i++){
        cout<< catalanMem(i,dp) <<" ";
    }
    cout << endl;
    return 0;
}