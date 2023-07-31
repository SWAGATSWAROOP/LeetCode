class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        vector<vector<int>> v(m+1,vector<int>(n+1));
        v[m][n] = 0;
        for(int i = n-1;i>=0;i--)v[m][i] = s2[i] + v[m][i+1];
        for(int i = m-1;i>=0;i--)v[i][n] = s1[i] + v[i+1][n];
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(s1[i] == s2[j])v[i][j] = v[i+1][j+1];
                else v[i][j] = min(s1[i]+v[i+1][j],s2[j]+v[i][j+1]);
            }
        }
        return v[0][0];
    }
};