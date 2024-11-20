class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            if(temp[i]!=nums[i]){
                start=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(temp[i]!=nums[i]){
                end=i;
                break;
            }
        }
        if(start==-1&&end==-1) return 0;
        return end-start+1;
        
    }
};