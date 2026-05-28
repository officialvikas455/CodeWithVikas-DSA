#include<iostream>
#include<vector>
#include<string>
using namespace std;

int f(int idx,int sum, vector<int> &num, vector<vector<int>> &dp){
    if(sum == 0) return 1;
    if(idx == 0) return num[0] == sum;

    if(dp[idx][sum] != -1) return dp[idx][sum];
    int notTake = f(idx-1,sum, num, dp);
    int take = 0;

    if(num[idx] <= sum){
        f(idx-1, sum-num[idx], num , dp);
    }
    return dp[idx][sum] = take + notTake;

}

int findWays(vector<int> num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1,0));
    int ans  = 0;
    return  ans = f(n-1, tar, num, dp);
    cout << ans << endl;

}

int main(){
    vector<int> num = {1,2,2,3,8,9,9};
    int n = 6;
    cout << findWays(n-1, num, tar, dp) << endl;
    return 0;
    
}