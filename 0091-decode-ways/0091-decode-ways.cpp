class Solution {
public:
    int count(string& s,int i,vector<int>& v){
        if(i >= s.size())return 1;
        if(s[i] == '0')return 0;
        if(v[i] != -1)return v[i];
        int c = count(s,i+1,v),d = 0;
        if((i+1 < s.size()) && (s[i] < '2' || (s[i] == '2' && s[i+1] <= '6')))d = count(s,i+2,v);
        return v[i] = c+d;
    }

    int numDecodings(string& s) {
        if(s[0] == '0')return 0;
        vector<int> v(s.size()+1,0);
        v[s.size()] = 1;
        for(int i = s.size()-1;i>=0;i--){
            int c = v[i+1],d = 0;
            if(s[i] == '0'){
                v[i] = 0;
                continue;
            }
            if(i+1 < s.size() && (s[i] < '2' || (s[i] == '2' && s[i+1] <= '6')))d = v[i+2];
            v[i] = c+d;
        }
        return v[0];
    }
};