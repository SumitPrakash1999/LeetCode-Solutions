class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int dx[]={0,0,1,-1};
                    int dy[]={1,-1,0,0};
                    for(int k=0;k<4;k++){
                        int newr=i+dx[k];
                        int newc=j+dy[k];
                        if(newr>=0&&newr<n&&newc>=0&&newc<n&&grid[newr][newc]==1){
                            int node=i*n+j;
                            int adjNode=newr*n+newc;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int> components;
                if(grid[i][j]==0){
                    int dx[]={0,0,1,-1};
                    int dy[]={1,-1,0,0};
                    for(int k=0;k<4;k++){
                        int newr=i+dx[k];
                        int newc=j+dy[k];
                        if(newr>=0&&newr<n&&newc>=0&&newc<n&&grid[newr][newc]==1){
                            int adjNode=newr*n+newc;
                            components.insert(ds.findUPar(adjNode));
                        }
                    }
                }
                int sz=0;
                for(auto it:components){
                    sz+=ds.size[it];
                }
                maxi=max(maxi,sz+1);
            }
        }
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findUPar(i)]);
        }
        return maxi;


        
    }
};