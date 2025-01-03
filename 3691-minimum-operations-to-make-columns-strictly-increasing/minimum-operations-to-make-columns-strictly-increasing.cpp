class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int j=0;j<m;j++){
            int last=grid[0][j];
            for(int i=1;i<n;i++){
                if(grid[i][j]>last){
                    last=grid[i][j];
                }                
                else{
                    cnt+=(last+1-grid[i][j]);
                    last++;
                }
            }
        }
        return cnt;
        
    }
};