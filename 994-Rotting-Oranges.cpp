class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int col = grid[0].size(),row = grid.size(),freshorange = 0;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 2)q.push({i,j});
                else if(grid[i][j] == 1)freshorange++;
            }
        }
        int ans = -1,sz;
        pair<int,int> front;
        int i,j;
        while(!q.empty()){
            sz = q.size();
            ans++;
            while(sz--){
                front = q.front();
                i = front.first;
                j = front.second;
                if(i - 1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                     freshorange--;
                    q.push({i-1,j});
                }
                if(j - 1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                     freshorange--;
                    q.push({i,j-1});
                }
                if(i + 1 < row && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                     freshorange--;
                    q.push({i+1,j});
                }
                if(j + 1 < col && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    freshorange--;
                    q.push({i,j+1});
                }
                q.pop();
            }
        }
        return (freshorange ? -1 : (ans == -1 ? 0 : ans));
    }
};