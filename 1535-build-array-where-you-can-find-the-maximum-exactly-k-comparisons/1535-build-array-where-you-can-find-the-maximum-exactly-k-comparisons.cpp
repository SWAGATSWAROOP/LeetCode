class Solution {
public:
    int mod = 1e9 + 7;
    int ways(int n,int m,int k,int i,int prev,vector<vector<vector<int>>>& v){
        if(i == n)return k == 0 ? 1:0;
        if(v[i][prev][k] != -1)return v[i][prev][k];
        int l = 0;
        if(k > 0){
            if(i){
                for(int j = 1;j <= prev;j++){
                    l = (l%mod + ways(n,m,k,i+1,prev,v)%mod)%mod;
                }
            }
            for(int j = prev+1;j <= m;j++){
                l = (l%mod + ways(n,m,k-1,i+1,j,v)%mod)%mod;
            }   
        }
        else{
            for(int j = 1;j <= prev;j++){
                l = (l%mod + ways(n,m,k,i+1,prev,v)%mod)%mod;
            }
        }
        return v[i][prev][k] = l%mod;
    }

    int numOfArrays(int n, int m, int k) {
        if(k > m)return 0;
        vector<vector<vector<int>>> v(n,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return ways(n,m,k,0,0,v);
    }
};