class Solution {
public:
    string dfs(unordered_map<string,vector<string>>& map,string s){
        int n = map[s].size();
        if(n == 0)return s;
        return dfs(map,map[s][0]);
    }

    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>> map;
        int n = paths.size();
        for(int i = 0;i<n;i++){
            map[paths[i][0]].push_back(paths[i][1]);
        }
        return dfs(map,paths[0][0]);
    }
};