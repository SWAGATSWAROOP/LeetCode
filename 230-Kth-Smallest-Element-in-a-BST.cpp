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
    void dfs(TreeNode* root,int& k,int& val){
        if(root->left){
            dfs(root->left,k,val);
        }
        if(k == 1){
            val = root->val;
        }
        k--;
        if(root->right){
            dfs(root->right,k,val);
        } 
    }

    int kthSmallest(TreeNode* root, int k) {
        int val;
        dfs(root,k,val);
        return val;
    }
};