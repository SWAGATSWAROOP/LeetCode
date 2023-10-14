class Solution {
public:
    int pW(vector<int>& cost,vector<int>& time,int i,int remt,vector<vector<int>>& v){
        if(remt <= 0)return 0;
        if(i == cost.size())return 1e9;
        if(v[i][remt] != -1)return v[i][remt];
        int a = pW(cost,time,i+1,remt,v);
        int b = pW(cost,time,i+1,remt-time[i]-1,v);
        if(b != 1e9)b += cost[i];
        return v[i][remt] = min(a,b);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int remt = cost.size();
        vector<vector<int>> v(cost.size(),vector<int>(cost.size()+1,-1));
        return pW(cost,time,0,remt,v);
    }
};