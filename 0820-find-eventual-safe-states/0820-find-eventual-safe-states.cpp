class Solution {
public:
    int dfs(vector<vector<int>>& graph,vector<int>& t,int index){
        if(t[index] != -2)return t[index];
        t[index] = -1;
        for(auto x:graph[index]){
            if(dfs(graph,t,x) <= 0)return t[index] = 0;
        }
        return t[index] = 1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> t(n,-2);
        for(int i = 0;i<n;i++){
            if(t[i] == -2){
                dfs(graph,t,i);
            }
        }
        int i = 0;
        for(int j = 0;j<n;j++){
            if(t[j]==1){
                t[i] = j;
                i++;
            }
        }
        int j = n-1;
        while(j >= 0 &&(!t[j] || t[j] < j)){
            t.pop_back();
            j--;
        }
        return t;
    }
};