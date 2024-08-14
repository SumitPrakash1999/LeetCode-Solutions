class Solution {
public:
    int solve(int ind,int amt, vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            if(amt%coins[0]==0) return amt/coins[0];
            else return 1e9;
        }
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int nottake=solve(ind-1,amt,coins,dp);
        int take=INT_MAX;
        if(coins[ind]<=amt) take=1+solve(ind,amt-coins[ind],coins,dp);

        return dp[ind][amt]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans=solve(n-1,amount, coins,dp);
        if(ans>=1e9) return -1;
        return ans;
        
    }
};