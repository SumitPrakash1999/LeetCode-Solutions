class Solution {
public:
    int solve(int ind,int target, vector<int> & nums){
        if(ind==0){
            if(target==0&&nums[ind]==0) return 2;
            if(target-nums[ind]==0||target+nums[ind]==0) return 1;
            else return 0;
        }
        int plus=solve(ind-1,target-nums[ind],nums);
        int minus=solve(ind-1,target+nums[ind],nums);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1,target,nums);
        
    }
};