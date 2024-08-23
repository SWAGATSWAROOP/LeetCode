class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        vector<int> inorder(numCourses,0);

        for(int i = 0;i < prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }
        
        queue<int> bfs;
        for(int i = 0;i < numCourses;i++){
            if(!inorder[i]){
                bfs.push(i);
            }
        }

        int front;
        while(!bfs.empty()){
            front = bfs.front();
            bfs.pop();
            ans.push_back(front);
            for(int i = 0;i < adj[front].size();i++){
                inorder[adj[front][i]]--;
                if(!inorder[adj[front][i]])bfs.push(adj[front][i]);
            }
        }

        return ans.size() != numCourses ?  vector<int>() : ans;
    }
};