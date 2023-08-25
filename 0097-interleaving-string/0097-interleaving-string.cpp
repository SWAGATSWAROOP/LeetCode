class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(),m = s2.size(),k = s3.size();
        if(k != m+n)return false;
        if(!m || !n)return s2 == s3 || s1 == s3;
        vector<bool> v(n+1,true);
        for(int i=m-1;i>=0;i--){
            v[n] = s2.substr(i) == s3.substr(n+i) ? true:false;
            for(int j = n-1;j>=0;j--){
                bool l = false,o = false;
                if(s2[i] == s3[i+j])l = v[j];
                if(s1[j] == s3[i+j])o = v[j+1];
                v[j] = l || o;
            }
        }
        return v[0];
    }
};