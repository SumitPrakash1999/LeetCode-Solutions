class Solution {
public:
    void floydWarshall(vector<vector<int>>& adj,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)adj[i][j]=0;
                if(adj[i][j]==-1) adj[i][j]=1e9;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1e9) adj[i][j]=-1;
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int> (n,-1));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
        floydWarshall(adj,n);
        vector<int> mpp(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&adj[i][j]!=-1&&adj[i][j]<=distanceThreshold) mpp[i]++;
            }
        }
        int mini=INT_MAX;
        int ele=-1;
        for(int i=0;i<n;i++){
            if(mini>=mpp[i]){
                mini=mpp[i];
                ele=i;
            }
        }
        return ele;        
    }
};