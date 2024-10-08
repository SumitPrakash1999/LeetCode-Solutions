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
        vector<vector<int>> after(2,vector<int> (k+1,0));

        for(int i=n-1;i>=0;i--){
            vector<vector<int>> cur(2,vector<int> (k+1,0));
            for(int j=0;j<=1;j++){
                for(int x=1;x<=k;x++){
                     long profit=0;
                        if(j==0){
                            profit=max(0+after[0][x],-prices[i]+after[1][x]);
                        }
                        else{
                            profit=max(0+after[1][x],prices[i]+after[0][x-1]);
                        }
                        cur[j][x]=profit;

                }
            }
            after=cur;
        }


        return after[0][k];
    }
};