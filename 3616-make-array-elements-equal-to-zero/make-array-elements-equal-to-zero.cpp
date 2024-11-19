class Solution {
public:
bool check(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0) return false; 
    }
    return true;

}
    int solve(int ind,int dir,vector<int> nums){
        while(ind>=0&&ind<nums.size()){
            if(nums[ind]==0)
            {
                if(dir==-1){
                    ind--;
                }
                else{
                    ind++;
                }
            }
            if(ind>=0&&ind<nums.size()&&nums[ind]>0){
                nums[ind]--;
                if(dir==-1){
                    ind++;
                    dir=1;
                }
                else{
                    ind--;
                    dir=-1;
                }
            }

        }
        if(check(nums)) return 1;
        return 0;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int val=solve(i,-1,nums);
                int val2=solve(i,1,nums);
                res+=val+val2;
            }
        }
        return res;
        
    }
};