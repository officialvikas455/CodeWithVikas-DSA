class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            if(n == 0) return 0;
    
            int hold = -prices[0]; // buying first stock
            int cash = 0;          // no stock in hand
    
            for(int i=1; i<n; i++){
                hold = max(hold, cash - prices[i]);             // buy or hold
                cash = max(cash, hold + prices[i] - fee);       // sell or rest
            }
            
            return cash;  // best profit when not holding at the end
        }
    };
    