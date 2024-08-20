class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || vis[i][j] || !grid[i][j])return;
        vis[i][j] = true;
        int xCoordinate[] = {0,0,-1,1};
        int yCoordinate[] = {-1,1,0,0};

        for(int l = 0;l < 4;l++){
            dfs(grid,i+xCoordinate[l],j+yCoordinate[l],vis);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0;i < n;i++){
            if(grid[i][0] && !visited[i][0]){
                dfs(grid,i,0,visited);
            }
            if(grid[i][m-1] && !visited[i][m-1]){
                dfs(grid,i,m-1,visited);
            }
        }
        for(int i = 0;i < m;i++){
            if(grid[0][i] && !visited[0][i]){
                dfs(grid,0,i,visited);
            }
            if(grid[n-1][i] && !visited[n-1][i]){
                dfs(grid,n-1,i,visited);
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
               if(!visited[i][j] && grid[i][j])ans += 1; 
            }
        }
        return ans;
    }
};