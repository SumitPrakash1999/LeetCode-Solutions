class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(auto it:dict){
                int start=i-it.length();
                if(start>=0&&dp[start]&&s.substr(start,it.length())==it){
                    dp[i]=true;
                    break;
                }
            }
        }    
            
        return dp[n];
        
    }
};