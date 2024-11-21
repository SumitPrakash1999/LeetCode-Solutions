class Solution {
public:
    // bool check(vector<int>& nums){
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]!=0) return false;
    //     }
    //     return true;
    // }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            freq[l]++;
            freq[r+1]--;
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=freq[i];
            if(sum<nums[i]) return false;
        }
        return true;        
    }
};