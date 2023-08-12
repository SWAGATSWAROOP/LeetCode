class Solution {
public:
    int mn(vector<int>& days, vector<int>& costs,int high,int i,vector<vector<int>>& v){
        if(i == days.size())return 0;
        if(v[i][high] != -1)return v[i][high];
        if(days[i] <= high){
            return v[i][high] = mn(days,costs,high,i+1,v);
        }
        int a = costs[0] + mn(days,costs,days[i],i+1,v);
        int b = costs[1] + mn(days,costs,days[i]+6,i+1,v);
        int c = costs[2] + mn(days,costs,days[i]+29,i+1,v);
        return v[i][high] = min(a,min(b,c));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> v(days.size(),vector<int>(396,-1));
        return mn(days,costs,0,0,v);
    }
};