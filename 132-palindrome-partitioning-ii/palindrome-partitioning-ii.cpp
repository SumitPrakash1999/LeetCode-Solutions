class Solution {
public:
    int solve(int i, int n, string s,vector<int>& dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=1e9;
        for(int k=i;k<n;k++){
            if(checkP(i,k,s)){
                int cnt=1+solve(k+1,n,s,dp);
                mini=min(mini,cnt);
            }           
           
        }
        return dp[i]=mini;
    }
    bool checkP(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int minCut(string &s) {
        int n=s.length();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=1e9;
            for(int k=i;k<n;k++){
                if(checkP(i,k,s)){
                    int cnt=1+dp[k+1];
                    mini=min(mini,cnt);
                }  
                        
            
            }
            dp[i]=mini;
       
        }      

        
        return dp[0]-1;        
    }
};