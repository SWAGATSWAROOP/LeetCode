class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size(),col = grid[0].size();
        int i = row - 1,j = 0;
        while(i >= 0 && j < col){
            if(grid[i][j] < 0){
                count += (col - j);
                i--;
            }
            else j++;
        }
        return count;
    }
};