class Solution {
public:
    void dfs(vector<vector<int>>& con,int i,vector<int>& vis,int& n){
        vis[i] = 1;
        for(int j = 0;j < n;j++){
            if(con[i][j] && !vis[j]){
                dfs(con,j,vis,n);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        int count = 0;
        vector<int> vis(sz,0);
        for(int i = 0;i < sz;i++){
            if(!vis[i]){
                dfs(isConnected,i,vis,sz);
                count++;
            }
        }
        return count;
    }
};