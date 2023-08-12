class Solution {
public:
    int mod = 1000000007;
    long long c(const int& low,const int& high,const int& zero,const int&one,int ind,vector<long long>& v){
        if(ind > high)return 0;
        if(v[ind] != -1)return v[ind];
        int k = 0;
        if(ind >= low && ind <= high)k++;
        long long o = c(low,high,zero,one,ind+one,v);
        long long z = c(low,high,zero,one,ind+zero,v);
        return v[ind] = (k%mod + o%mod + z%mod)%mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> v(high+1,-1);
        return c(low,high,zero,one,0,v);
    }
};