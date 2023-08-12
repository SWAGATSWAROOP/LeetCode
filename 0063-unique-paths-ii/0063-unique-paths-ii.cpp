class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool ob = false;
        grid[0][0] = grid[0][0] == 1 ? 0:1;
        if(!grid[0][0])return 0;
        for(int i=1;i<n;i++){
            if(grid[i][0] || ob){
                grid[i][0] = 0;
                ob = true;
            }
            else grid[i][0] = 1;
        }
        ob = false;
        for(int j=1;j<m;j++){
            if(grid[0][j] || ob){
                grid[0][j] = 0;
                ob = true;
            }
            else grid[0][j] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!grid[i][j])grid[i][j] = grid[i-1][j] + grid[i][j-1];
                else grid[i][j] = 0;
            }
        }
        return grid[n-1][m-1];
    }
};