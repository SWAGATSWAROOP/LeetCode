class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        int row = matrix.size(),col = matrix[0].size();
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(!matrix[i][j])zeros.push_back({i,j});
            }
        }

        for(auto x:zeros){
            for(int i = 0;i < row;i++)matrix[i][x.second] = 0;
            for(int i = 0;i < col;i++)matrix[x.first][i] = 0;
        }
    }
};