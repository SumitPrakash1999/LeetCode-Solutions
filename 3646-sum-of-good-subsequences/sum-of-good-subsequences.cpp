class Solution {
public:    
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n=nums.size();
        int ct=1e9+7;
        int res=0;
        unordered_map<int,long long> count,total;//count[i] is no of subseq ending with i and total[i] is the sum of all subseq ending with i
        for(int it:nums){
            count[it]=(count[it]+count[it-1]+count[it+1]+1)%ct;
            total[it]=(total[it]+total[it-1]+total[it+1]+1ll*it*(count[it-1]+count[it+1]+1))%ct;
            res=(res+total[it-1]+total[it+1]+1ll*it*(count[it-1]+count[it+1]+1))%ct;
        }  
        
        return res;
    }
};