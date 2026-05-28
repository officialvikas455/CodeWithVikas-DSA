#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int> nums, int target){
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
    
    // Initialize base case - empty subset can form sum 0
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Print DP table
    cout << "DP Table:\n";
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return dp[n][target];
}

int main(){
    vector<int> nums = {4,2,7,1,3};
    int target = 6;

    cout << "Can Peform\n" << (targetSum(nums, target) ? "Yes" : "No") << endl;
    return 0;
}