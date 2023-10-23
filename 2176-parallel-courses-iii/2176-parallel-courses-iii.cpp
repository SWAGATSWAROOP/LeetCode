struct comp {
    bool operator()(const pair<int, int*>& a, const pair<int, int*>& b) {
        return *a.second > *b.second; 
    }
};

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1,0);
        unordered_map<int,int> inside;
        int tim = 0;
        for(auto x:relations){
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        priority_queue<pair<int,int*>,vector<pair<int,int*>>,comp> topo;
        for(int i = 1;i<=n;i++){
            if(!indegree[i]){
                topo.push(make_pair(i,&time[i-1]));
                inside[i]++;
            }
        }
        while(!topo.empty()){
            pair<int,int*> top = topo.top();
            topo.pop();
            int i = top.first;
            int t = *top.second;
            inside.erase(i);
            for(auto x:inside){
                time[x.first-1] -= t; 
            }
            for(int x:graph[i]){
                indegree[x]--;
                if(!indegree[x]){
                    topo.push(make_pair(x,&time[x-1]));
                    inside[x]++;
                }
            }
            tim += t;
        }
        return tim;
    }
};