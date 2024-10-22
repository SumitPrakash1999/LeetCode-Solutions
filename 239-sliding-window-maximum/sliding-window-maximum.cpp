class Solution {
public:
    // int findMax(int l,int r,vector<int> & nums){
    //     int ans=-1e9;
    //     for(int i=l;i<=r;i++){
    //         ans=max(ans,nums[i]);
    //     }
    //     return ans;
    // }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!dq.empty()&&dq.front()<=i-k) dq.pop_front();
            while(!dq.empty()&&nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
        
    }
};