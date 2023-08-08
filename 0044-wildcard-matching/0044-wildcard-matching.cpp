class Solution {
public:
    int M(string& s,string& p,int i,int j,vector<vector<int>>& v){
        if(i > s.size() && j > p.size())return 1;
        if(i > s.size() || j > p.size() || (s[i] != '?' && s[i] != '*' && p[j] != '?' && p[j] != '*' && s[i]!=p[j]))return 0;
        if(v[i][j] != -1)return v[i][j];
        int m = M(s,p,i+1,j+1,v);
        int n =  0,k = 0;
        if(s[i] == '*' || p[j] == '*'){
            n = M(s,p,i,j+1,v);
            k = M(s,p,i+1,j,v);
        }
        return v[i][j] = m || n || k;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> v(s.size()+1,vector<int>(p.size()+1,-1));
        return M(s,p,0,0,v);
    }
};