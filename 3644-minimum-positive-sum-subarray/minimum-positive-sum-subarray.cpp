class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        set<int> st;
        for(int i=l;i<=r;i++) st.insert(i);
        int mini=INT_MAX;
        int sum;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int len=j-i+1;
                if(st.find(len)!=st.end()&&sum>0){
                    mini=min(mini,sum);
                }
                // cout<<sum<<" ";
            }
        }
        if(mini==0||mini==INT_MAX) return -1;
        return mini;        
    }
};