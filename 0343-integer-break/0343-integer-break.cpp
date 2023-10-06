class Solution {
public:
    int mxp(int n,vector<int>& v){
        if(n <= 3)return n;
        if(v[n])return v[n];
        int mx = 0;
        for(int i = 1;i<=n;i++)mx = max(mx,i*mxp(n-i,v));
        return v[n]  = mx;
    }

    int integerBreak(int n) {
        if(n < 4)return n-1;
        vector<int> v(n+1);
        return mxp(n,v);
    }
};