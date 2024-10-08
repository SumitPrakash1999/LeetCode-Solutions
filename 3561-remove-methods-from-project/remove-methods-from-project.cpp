class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(n,0);
        dfs(k,vis,adj);

        bool ans=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bool temp=false;
                for(auto it:adj[i]){
                    if(vis[it]){
                        temp=true;
                        break;
                    }
                }
                if(temp){
                    ans=true;
                    break;
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(vis[i]){
                if(ans) res.push_back(i);
            }
            else{
                res.push_back(i);
            }
        }
        return res;
        
    }
};