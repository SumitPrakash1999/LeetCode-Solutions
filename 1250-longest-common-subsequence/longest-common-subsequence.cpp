class Solution {
public:
    // int solve(int i, int j, string t1, string t2,vector<vector<int>>& dp){
    //     if(i<0||j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(t1[i]==t2[j]) return dp[i][j]=1+solve(i-1,j-1,t1,t2,dp);
    //     else return dp[i][j]=max(solve(i-1,j,t1,t2,dp),solve(i,j-1,t1,t2,dp));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(text1[i]==text2[j]){
                        dp[i][j]=1;
                        if(i-1>=0&&j-1>=0)dp[i][j]+=dp[i-1][j-1];
                    } 
                    else{
                        int l=0,r=0;
                        if(i-1>=0) l=dp[i-1][j];
                        if(j-1>=0) r=dp[i][j-1];
                        dp[i][j]=max(l,r);
                    } 
                            

            }
        }
        return dp[n-1][m-1];
    }
};