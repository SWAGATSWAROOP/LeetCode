class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m,vector<int>(n,1));
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                v[j][i] = v[j-1][i] + v[j][i-1];
            }
        }
        return v[m-1][n-1];
    }
};