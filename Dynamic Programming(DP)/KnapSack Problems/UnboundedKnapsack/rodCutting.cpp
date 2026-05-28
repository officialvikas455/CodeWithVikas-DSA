
class Solution {
    public:
        int rec(vector<int> &price, vector<int> &length, int rodLength) {
            int n = price.size();
            vector<vector<int>> dp(n+1, vector<int>(rodLength+1, 0));
    
            for(int i=1; i<n+1; i++){
                for(int j=1; j<=rodLength; j++){
                    if(length[i-1] <= j){
                        dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][rodLength];
        }
    
        int cutRod(vector<int> &price) {
            int n = price.size();
            vector<int> length(n);
            for(int i=0; i<n; i++) length[i] = i+1; // rod lengths 1..n
    
            return rec(price, length, n);
        }
    };
    