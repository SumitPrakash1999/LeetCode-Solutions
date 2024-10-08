class Solution {
public:
    int solve(int ind, int n, vector<int>& prices ,int trans, vector<vector<int>>& dp){
        if(ind==n||trans==4){
            return 0;
        }
        if(dp[ind][trans]!=-1){return dp[ind][trans];}
        int profit=0;
        if(trans%2==0){
            profit=max(0+solve(ind+1,n,prices,trans,dp),-prices[ind]+solve(ind+1,n,prices,trans+1,dp));
        }
        else{
            profit=max(0+solve(ind+1,n,prices,trans,dp),prices[ind]+solve(ind+1,n,prices,trans+1,dp));
        }
        return dp[ind][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        // vector<vector<int>> after(2,vector<int> (3,0));
        // vector<vector<int>> cur(2,vector<int> (3,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=0;j<=1;j++){
        //         for(int k=1;k<=2;k++){
        //             int profit=0;
        //             if(j==0){
        //                 profit=max(0+after[0][k],-prices[i]+after[1][k]);
        //             }
        //             if(j==1){
        //                 profit=max(0+after[1][k],prices[i]+after[0][k-1]);
        //             }
        //             cur[j][k]=profit;
                    
        //         }
        //     }
        //     after=cur;
        // }
        // return after[0][2];
        return solve(0,n,prices,0,dp);
        
    }
};