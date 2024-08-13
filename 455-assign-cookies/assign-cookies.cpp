class Solution {
public:
    int solve(int i, int j, int n, int m,vector<int>& g, vector<int>& s){
        if(i==n||j==m) return 0;
   
        int give=0;
        if(s[j]>=g[i]){
            give=1+solve(i+1,j+1,n,m,g,s);
        }else return solve(i,j+1,n,m,g,s);
        return give;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        return solve(0,0,n,m,g,s);
        
    }
};