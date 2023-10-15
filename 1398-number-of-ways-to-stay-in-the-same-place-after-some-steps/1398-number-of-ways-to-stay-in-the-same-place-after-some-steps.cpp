class Solution {
public:
    int mod = 1e9+7; 
    int NW(int i,int steps,int l,vector<vector<int>>& v){
        if(!steps && i == 0)return 1;
        if(i == l || i < 0 || !steps)return 0;
        if(v[i][steps] != -1)return v[i][steps];
        int left = NW(i-1,steps-1,l,v)%mod;
        int right = NW(i+1,steps-1,l,v)%mod;
        int stay = NW(i,steps-1,l,v)%mod;
        return v[i][steps] = ((left+right)%mod+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> v(steps+1,vector<int>(steps+1,-1));
        return NW(0,steps,arrLen,v);
    }
};