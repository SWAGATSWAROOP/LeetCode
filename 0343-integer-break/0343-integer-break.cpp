class Solution {
public:
    int mxp(int n,int prod,vector<unordered_map<int,int>>& v){
        if(!n)return prod;
        if(v[n].count(prod))return v[n][prod];
        int mx = 0;
        for(int i = 1;i<=n;i++)mx = max(mx,mxp(n-i,i*prod,v));
        return v[n][prod]  = mx;
    }

    int integerBreak(int n) {
        if(n < 4)return n-1;
        vector<unordered_map<int,int>> v(n+1);
        return mxp(n,1,v);
    }
};