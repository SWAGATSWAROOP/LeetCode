class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(),col = matrix[0].size();
        vector<pair<int,int>> v;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(!matrix[i][j])v.push_back({i,j});
            }
        }
        int sz = v.size();
        for(int i = 0;i < sz;i++){
            for(int j = 0;j < row;j++)matrix[j][v[i].second] = 0;
            for(int j = 0;j < col;j++)matrix[v[i].first][j] = 0;
        }
    }
};