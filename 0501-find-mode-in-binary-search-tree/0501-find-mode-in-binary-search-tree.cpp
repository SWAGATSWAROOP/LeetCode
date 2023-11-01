/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> map;
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            map[front->val]++;
            q.pop();
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        int mx = 0;
        for(auto x:map){
            if(x.second > mx){
                mx = x.second;
                v.clear();
                v.push_back(x.first);
            }
            else if(x.second == mx){
                v.push_back(x.first);
            }
        }
        return v;
    }
};