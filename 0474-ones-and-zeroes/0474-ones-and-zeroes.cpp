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

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> v(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int l = findMx(strs,m,n,0,v);
        return l;
    }
};