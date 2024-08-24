class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses,0);
        int n = prerequisites.size();
        int count = 0;
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0;i < prerequisites.size();i++){
            inorder[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0;i < numCourses;i++){
            if(!inorder[i]){
                q.push(i);
            }
        }

        int front;
        cout<<count<<endl;

        while(!q.empty()){
            front = q.front();
            count++;
            cout<<count<<endl;
            q.pop();
            for(auto x:adj[front]){
                inorder[x]--;
                if(!inorder[x]){
                    q.push(x);
                }
            }
        }
        return count == numCourses;
    }
};