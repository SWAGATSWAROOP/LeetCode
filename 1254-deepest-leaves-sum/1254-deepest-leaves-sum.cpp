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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            sum = 0;
            int size = q.size();
            while(size--){
                TreeNode* f = q.front();
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                sum += f->val;
            }
        }
        return sum;
    }
};