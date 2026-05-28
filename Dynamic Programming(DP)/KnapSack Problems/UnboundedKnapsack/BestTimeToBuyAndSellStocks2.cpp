class Solution {
    public:
    
       int rec(int i, vector<int> &prices, int buyStocks,int n, vector<vector<int>> &dp){
        if(i==n){
            return 0;
        }
        // check if subproblem is alreadsy exits 
        if(dp[i][buyStocks] != -1){
            return dp[i][buyStocks];
        }
            int ans=0;
    
            if(buyStocks ==0){
                int buy =-prices[i]+ rec(i+1, prices, 1, n, dp);
                int notBuy = rec(i+1, prices, 0, n, dp);
                 ans = max(buy, notBuy);
            }else{ // buyststus
                int sell = prices[i] + rec(i+1,prices, 0,n ,dp);
                int notSell = rec(i+1,prices,1, n, dp);
    
                ans = max(sell, notSell);
    
            }
            dp[i][buyStocks] = ans;
            return ans;
     }
      
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>> dp(n,vector<int>(2,-1));
            return rec(0,prices,0, n,dp);
            
        }
    };