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
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2,vector<int> (3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    int profit=0;
                    if(j==0){
                        profit=max(0+dp[i+1][0][k],-prices[i]+dp[i+1][1][k]);
                    }
                    if(j==1){
                        profit=max(0+dp[i+1][1][k],prices[i]+dp[i+1][0][k-1]);
                    }
                    dp[i][j][k]=profit;
                    
                }
            }
        }
        return dp[0][0][2];
        
    }
};