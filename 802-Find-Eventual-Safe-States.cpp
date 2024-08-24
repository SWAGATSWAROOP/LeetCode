class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjRev(n);
        vector<int> inorder(n,0);
        for(int i = 0;i < n;i++){
            for(int x:graph[i]){
                adjRev[x].push_back(i);
                inorder[i]++;
            }
        }

        queue<int> q;

        for(int i = 0;i < n;i++){
            if(!inorder[i]){
                q.push(i);
            }
        }

        vector<int> ans;
        int front;
        while(!q.empty()){
            front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto x:adjRev[front]){
                inorder[x]--;
                if(!inorder[x]){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};