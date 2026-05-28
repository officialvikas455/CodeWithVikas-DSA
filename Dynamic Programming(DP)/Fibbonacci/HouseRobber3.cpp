#include<iostream>
#include<vector>
#include<map>
using namespace std;
    
       int rec(TreeNode* curr, unordered_map<TreeNode*, int> &dp){
        if(curr==NULL){
            return 0;
        }
        if(dp[curr] != NULL){
            return dp[curr];
        }
        int steal = curr->val;
    
        if(curr->left != NULL){
            steal += rec(curr->left->left,dp) + rec(curr->left->right,dp);
        }
        if(curr->right != NULL){
            steal += rec(curr->right->left,dp) + rec(curr->right->right,dp);
        }
        int notSteal = rec(curr->left,dp) + rec(curr->right,dp);
    
        int ans = max(steal, notSteal);
        dp[curr] = ans;
        return ans;
       }
        int rob(TreeNode* root) {
            unordered_map<TreeNode*, int> dp;
            return rec(root,dp);
            
        }