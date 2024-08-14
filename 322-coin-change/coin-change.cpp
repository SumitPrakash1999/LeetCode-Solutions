class Solution {
public:
    // int solve(int ind,int amt, vector<int>& coins,vector<vector<int>> &dp){
    //     if(ind==0){
    //         if(amt%coins[0]==0) return amt/coins[0];
    //         else return 1e9;
    //     }
    //     if(dp[ind][amt]!=-1) return dp[ind][amt];
    //     int nottake=solve(ind-1,amt,coins,dp);
    //     int take=INT_MAX;
    //     if(coins[ind]<=amt) take=1+solve(ind,amt-coins[ind],coins,dp);

    //     return dp[ind][amt]=min(take,nottake);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0);

        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0) prev[t]=t/coins[0];
            else prev[t]=1e9;
        }

        for(int i=1;i<n;i++){
            vector<int> cur(amount+1,0);
            for(int t=0;t<=amount;t++){
                int nottake=prev[t];
                int take=INT_MAX;
                if(coins[i]<=t) take=1+cur[t-coins[i]];

                cur[t]=min(take,nottake);

            }
            prev=cur;
        }


        int ans=prev[amount];
        if(ans>=1e9) return -1;
        return ans;
        
    }
};