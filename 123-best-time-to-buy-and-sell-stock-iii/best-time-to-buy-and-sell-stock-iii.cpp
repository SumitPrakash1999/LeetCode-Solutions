class Solution {
public:
    int solve(int ind, int n, vector<int>& prices ,int buy, int cap, vector<vector<vector<int>>>& dp){
        if(ind==n||cap==0){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){return dp[ind][buy][cap];}
        int profit=0;
        if(buy==0){
            profit=max(0+solve(ind+1,n,prices,0,cap,dp),-prices[ind]+solve(ind+1,n,prices,1,cap,dp));
        }
        if(buy==1){
            profit=max(0+solve(ind+1,n,prices,1,cap,dp),prices[ind]+solve(ind+1,n,prices,0,cap-1,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int> (3,-1)));
        return solve(0,n,prices,0,2,dp);
        
    }
};