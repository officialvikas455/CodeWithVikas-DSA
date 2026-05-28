class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
    
            if (n == 1) {
                return nums[0];
            }
    
            vector<int> dp(n, 0);
    
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
    
            for (int i = 2; i < n; i++) {
                dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            }
    
            return dp[n - 1];        
        }
    };

 //// Second Solution

    class Solution {
        public:
            int rec(int i, vector<int>& nums, int n, vector<int>& dp) {
                if (i >= n) return 0; 
                int ans=0;// base case
        
                if (dp[i] != -1) return dp[i]; // already solved
        
                int steal = nums[i] + rec(i + 2, nums, n, dp);
                int notsteal = rec(i + 1, nums, n, dp);
        
                return dp[i] = max(steal, notsteal);
                dp[i] = ans;
                return ans;
                
            }
        
            int rob(vector<int>& nums) {
                int n = nums.size();
                vector<int> dp(n, -1);
                return rec(0, nums, n, dp);
            }
        };
        