class Solution {
public:
    int solve(int ind, int buy, int n, vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=n) return 0;
        long profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==0){
            profit=max(0+solve(ind+1,0,n,prices,dp),-prices[ind]+solve(ind+1,1,n,prices,dp));
        }
        else{
            profit=max(0+solve(ind+1,1,n,prices,dp),prices[ind]+solve(ind+2,0,n,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,0,n,prices,dp);
        
    }
};