class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        int ans=0;
        for(auto it:nums){
            mpp[it]++;
        }    
        int left=0,right=0;
        for(int mid=0;mid<n;mid++){
            while(nums[mid]-nums[left]>k) left++;
            while(right<n-1&&nums[right+1]-nums[mid]<=k) right++;
            int total=right-left+1;
            ans=max(ans,min(total-mpp[nums[mid]],numOperations)+mpp[nums[mid]]);
        }
        left=0;
        for(right=0;right<n;right++){
            int mid=(nums[left]+nums[right])/2;
            while(mid-nums[left]>k||nums[right]-mid>k){
                left++;
                mid=(nums[left]+nums[right])/2;
            }
            ans=max(ans,min(right-left+1,numOperations)); 
        }
        return ans;
    }
};