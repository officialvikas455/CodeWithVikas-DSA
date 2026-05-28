#include<iostream>
#include<vector>
using namespace std;

int getMinDiff(vector<int> &nums){
    int totSum = 0;
    int n = nums.size();

    for(int el : nums){
        totSum += el;
    }
    int W = totSum/2;
    vector<vector<int>> dp(n+1, vector<int>(W+1,0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(nums[i-1] <= j){ // exclude case
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }else{ // include case
                dp[i][j] = nums[i-1][j];
            }
        }
    }
    int grpSum = dp[n][W];
    int grpSum2 = totSum - grpSum;

    return abs(grpSum - grpSum2);

}

int main(){
    vector<int> nums = {1,6,11,5};

    cout << getMinDiff(nums) << endl;
    return 0;
}