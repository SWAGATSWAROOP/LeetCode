class Solution {
public:
    int mnDel(string& s1,string& s2,int i,int j,vector<vector<int>>& v){
        if(i == s1.size() && j == s2.size())return 0;
        if(v[i][j] != -1)return v[i][j];
        if(i == s1.size()){
            int sum = 0;
            int m = j;
            for(;j<s2.size();j++)sum += s2[j];
            return v[i][m] = sum;
        }
        if(j == s2.size()){
            int sum = 0;
            int m = i;
            for(;i<s1.size();i++)sum += s1[i];
            return v[m][j] = sum;
        }
        if(s1[i] == s2[j])return mnDel(s1,s2,i+1,j+1,v);
        int k = s1[i] + mnDel(s1,s2,i+1,j,v);
        int z = s2[j] + mnDel(s1,s2,i,j+1,v);
        return v[i][j] = min(k,z);
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> v(s1.size()+1,vector<int>(s2.size()+1,-1));
        return mnDel(s1,s2,0,0,v);
    }
};