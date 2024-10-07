class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            for(int prev_ind=0;prev_ind<i;prev_ind++){
                if(nums[i]>nums[prev_ind]&&dp[i]<1+dp[prev_ind]){
                    dp[i]=1+dp[prev_ind];
                    cnt[i]=cnt[prev_ind];
                }
                else if(nums[i]>nums[prev_ind]&&dp[i]==1+dp[prev_ind]){
                    cnt[i]+=cnt[prev_ind];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]) nos+=cnt[i];
        }
        return nos;
        
    }
};