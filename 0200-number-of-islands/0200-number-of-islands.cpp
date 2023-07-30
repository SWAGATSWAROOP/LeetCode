class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int row,int col){
        if(i >= row || j >= col || j < 0 || i < 0 || grid[i][j] == '0')return;
        grid[i][j] = '0';
        dfs(grid,i+1,j,row,col);
        dfs(grid,i,j+1,row,col);
        dfs(grid,i,j-1,row,col);
        dfs(grid,i-1,j,row,col);
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(),col = grid[0].size();
        int count = 0;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == '0')continue;
                dfs(grid,i,j,row,col);
                count++;
            }
        }
        return count;
    }
};