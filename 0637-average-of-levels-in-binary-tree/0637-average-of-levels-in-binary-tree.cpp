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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> v;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int l = size;
            double a = 0;
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                a += front->val;
            }
            a /= l;
            v.push_back(a);
        }
        return v;
    }
};