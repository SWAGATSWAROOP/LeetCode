class Solution {
public:
    int match(string& s,string& p,int i,int j,vector<vector<int>>& v){
        if(j >= p.size())return i >= s.size() ? 1:0; 
        if(i >= s.size()){
            if(j >= p.size())return 1;
            if(p[p.size()-1] != '*')return 0;
            while(j < p.size()){
                if(p[j] != '*' && j+1 < p.size() && p[j+1]!='*')return 0;
                j++;
            }
            return 1;
        }
        if(v[i][j] != -1)return v[i][j];
        if(p[j] == '*'){
            int k = j;
            while(p[k]=='*')k--;
            if(p[k]!= '.' && p[k]!=s[i])return match(s,p,i,j+1,v);
            return v[i][j] = match(s,p,i+1,j+1,v) || match(s,p,i,j+1,v) || match(s,p,i+1,j,v);
        }
        else if(j+1 < p.size() && p[j+1] == '*'){
            int l =  match(s,p,i,j+2,v),o = 0;
            if(s[i] == p[j] || p[j] == '.')o = match(s,p,i+1,j+1,v);
            return v[i][j] = o || l;
        }
        else if(s[i]!=p[j] && p[j]!='.')return 0;
        return v[i][j] = match(s,p,i+1,j+1,v);
    }

    bool isMatch(string& s, string& p) {
        vector<vector<int>> v(s.size(),vector<int>(p.size(),-1));
        return match(s,p,0,0,v);
    }
};