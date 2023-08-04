class Solution {
public:
    int findMx(vector<string>& s,int m,int n,int i,vector<vector<vector<int>>>& v){
        if((!m && !n) || i == s.size())return 0;
        if(v[i][m][n] != -1)return v[i][m][n];
        int l = 0;
        int z = m-count(s[i].begin(),s[i].end(),'0');
        int y = n-count(s[i].begin(),s[i].end(),'1');
        if(z >= 0 && y >= 0)l = 1+findMx(s,z,y,i+1,v);
        int k = findMx(s,m,n,i+1,v);
        return v[i][m][n] =  max(l,k);
    }

    int findMaxForm(vector<string>& s, int m, int n) {
        vector<vector<int>> prev(m+1,vector<int>(n+1,0)),curr(m+1,vector<int>(n+1,0));
        for(int i = 0;i<s.size();i++){
            for(int j = 0;j<=m;j++){
                for(int k = 0;k<=n;k++){
                    int l = 0;
                    int z = j-count(s[i].begin(),s[i].end(),'0');
                    int y = k-count(s[i].begin(),s[i].end(),'1');
                    if(z >= 0 && y >= 0)l = 1+prev[z][y];
                    int u = prev[j][k];
                    curr[j][k] =  max(l,u);
                }
            }
            prev = curr;
        }
        return prev[m][n];
    }
};