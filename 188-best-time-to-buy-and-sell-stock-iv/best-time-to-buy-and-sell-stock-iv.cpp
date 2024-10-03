class Solution {
public:
    int solve(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind==n||cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        long profit=0;
        if(buy==0){
            profit=max(0+solve(ind+1,0,cap,n,prices,dp),-prices[ind]+solve(ind+1,1,cap,n,prices,dp));
        }
        else{
            profit=max(0+solve(ind+1,1,cap,n,prices,dp),prices[ind]+solve(ind+1,0,cap-1,n,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return solve(0,0,k,n,prices,dp);
    }
};