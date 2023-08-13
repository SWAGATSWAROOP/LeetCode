class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edge) {
        unordered_map<int,unordered_set<int>> map;
        for(int i = 1;i<=n;i++)map[i];
        for(int i = 0;i<edge.size();i++){
            map[edge[i][0]].insert(edge[i][1]);
            map[edge[i][1]].insert(edge[i][0]);
        }
        int nnodes = map.size();
        int codd = 0;
        vector<int> v;
        for(auto i:map){
            if(i.second.size() & 1){
                codd++;
                v.push_back(i.first);
                if(i.second.size() == nnodes-1)return false;
            }
            if(codd > 4)return false;
        }
        if(!codd)return true;
        if(codd & 1)return false;
        if(codd == 2){
            if(map[v[0]].find(v[1])==map[v[0]].end())return true;
            else{
                for(auto x:map){
                    if(x.first == v[0] || x.first == v[1])continue;
                    if(map[v[0]].find(x.first)==map[v[0]].end() && map[v[1]].find(x.first)==map[v[1]].end())return true;
                }
            }
            return false;
        }
        else{
            if(map[v[0]].find(v[1])==map[v[0]].end() && map[v[2]].find(v[3])==map[v[2]].end())return true;
            if(map[v[0]].find(v[2])==map[v[0]].end() && map[v[1]].find(v[3])==map[v[1]].end())return true;
            if(map[v[0]].find(v[3])==map[v[0]].end() && map[v[1]].find(v[2])==map[v[1]].end())return true;
        }
        return false;
    }
};
