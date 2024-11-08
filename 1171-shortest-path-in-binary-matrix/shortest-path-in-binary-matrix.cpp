class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<vector<int>> dist(n,vector<int> (n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        vis[0][0]=1;
        dist[0][0]=1;
        int dx[]={0,0,1,-1,-1,1,-1,1};
        int dy[]={1,-1,0,0,-1,1,1,-1};
        while(!pq.empty()){
            int dis=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<n&&grid[nx][ny]==0&&vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    if(dist[nx][ny]>dis+1){
                        dist[nx][ny]=dis+1;
                        pq.push({dis+1,{nx,ny}});
                    }
                }
            }
            
        }
        if(dist[n-1][n-1]==1e9) return -1;
        return dist[n-1][n-1];

        
    }
};