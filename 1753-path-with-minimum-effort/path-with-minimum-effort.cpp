class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int dis=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==n-1&&y==m-1) return dis;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int newVal=max(dis,abs(heights[x][y]-heights[nx][ny]));
                    if(newVal<dist[nx][ny]){
                    dist[nx][ny]=newVal;
                    q.push({newVal,{nx,ny}});
                    }
                }
            }


        }
        return 0;
        
    }
};