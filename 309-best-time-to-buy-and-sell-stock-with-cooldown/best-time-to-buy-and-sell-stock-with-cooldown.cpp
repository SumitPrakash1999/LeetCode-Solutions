class Solution {
public:
    int solve(int ind, int buy, int n, vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=n) return 0;
       
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long profit=0;
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
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                long profit=0;
                if(j==0){
                    profit=max(0+dp[i+1][0],-prices[i]+dp[i+1][1]);
                }
                else{
                    if(i>=n-1){
                        profit=max(0+dp[i+1][1],prices[i]);
                    }
                    else{
                        profit=max(0+dp[i+1][1],prices[i]+dp[i+2][0]);
                    }
                    
                }
                dp[i][j]=profit;

            }
        }

        return dp[0][0];
        
    }
};