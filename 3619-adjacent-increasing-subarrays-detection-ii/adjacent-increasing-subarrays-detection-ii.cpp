class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int maxi=1,prev_maxi=0;
        int res=INT_MIN;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])maxi++;
            else{
                prev_maxi=maxi;
                maxi=1;
            }
            res=max({res,min(prev_maxi,maxi),maxi/2});
        }
        return res;
    }
};