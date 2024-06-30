class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> in(n,0);
        int sz = edges.size();
        for(int i = 0;i < sz;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            in[edges[i][1]]++;
        }
        
        vector<vector<int>> ans(n);
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(!in[i]){
                q.push(i);
            }
        }
        int front;
        vector<int> topOrder;
        while(!q.empty()){
            front = q.front();
            topOrder.push_back(front);
            for(int i = 0;i < adj[front].size();i++){
                in[adj[front][i]]--;
                if(!in[adj[front][i]]){
                    q.push(adj[front][i]);
                }
            }
            q.pop();
        }
        vector<set<int>> anc(n);
        for(int x:topOrder){
            for(int y:adj[x]){
                anc[y].insert(x);
                anc[y].insert(anc[x].begin(),anc[x].end());
            }
        }
        for(int i = 0;i < n;i++){
            ans[i].assign(anc[i].begin(),anc[i].end());
        }
        return ans;
    }
};