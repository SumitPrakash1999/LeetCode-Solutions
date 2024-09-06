class Solution {
public:
    // int solve(int ind,int target, vector<int> & nums,vector<vector<int>>& dp){
    //     if(ind==0){
    //         if(target==0&&nums[0]==0) return 2;
    //         if(target==0||nums[0]==target) return 1;
    //         else return 0;
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     int minus=solve(ind-1,target,nums,dp);
    //     int plus=0;
    //     if(nums[ind]<=target)  plus=solve(ind-1,target-nums[ind],nums,dp);
    //     return dp[ind][target]=plus+minus;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++) tot+=nums[i];
        if(tot-target<0) return 0;
        if((tot-target)%2==1) return 0;
        int sum2=(tot-target)/2;
        vector<vector<int>> dp(n,vector<int> (sum2+1,0));

        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;

        if(nums[0]!=0&&nums[0]<=sum2) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum2;j++){
                int minus=dp[i-1][j];
                int plus=0;
                if(nums[i]<=j)  plus=dp[i-1][j-nums[i]];
                dp[i][j]=plus+minus;
            }
        }
        return dp[n-1][sum2];
        
    }
};