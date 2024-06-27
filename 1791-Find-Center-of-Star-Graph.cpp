class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        int n = edges.size();
        int mx = -1;
        for(int i = 0;i < n;i++){
            map[edges[i][0]]++;
            map[edges[i][1]]++;
            mx = max(mx,max(edges[i][0],edges[i][1]));
        }
        mx -= 1;
        for(auto x:map){
            if(x.second == mx){
                return x.first;
            }
        }
        return -1;
    }
};