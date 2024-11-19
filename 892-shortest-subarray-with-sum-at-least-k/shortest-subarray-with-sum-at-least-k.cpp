class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int res=1e9;
        vector<long long> prefix(n,0);
        prefix[0]=1ll*nums[0];
        deque<int> d;
        for(int i=0;i<n;i++){
            if(i>0){
                prefix[i]=prefix[i-1]+nums[i];
            }
            if(prefix[i]>=k) res=min(res,i+1);
            while(!d.empty()&&prefix[i]-prefix[d.front()]>=k){
                res=min(res,i-d.front());
                d.pop_front();
            } 
            while(!d.empty()&&prefix[i]<=prefix[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        return res==1e9?-1:res;
        
    }
};