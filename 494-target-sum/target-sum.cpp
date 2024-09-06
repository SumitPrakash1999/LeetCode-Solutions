class Solution {
public:
    int solve(int ind,int target, vector<int> & nums,vector<vector<int>>& dp){
        if(ind==0){
            if(target==0&&nums[0]==0) return 2;
            if(target==0||nums[0]==target) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int minus=solve(ind-1,target,nums,dp);
        int plus=0;
        if(nums[ind]<=target)  plus=solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++) tot+=nums[i];
        if(tot-target<0) return 0;
        if((tot-target)%2==1) return 0;
        int sum2=(tot-target)/2;
        vector<vector<int>> dp(n,vector<int> (sum2+1,-1));
        return solve(n-1,sum2,nums,dp);
        
    }
};