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
    void p(TreeNode* root,vector<int>& v){
        if(!root)return;
        v.push_back(root->val);
        p(root->left,v);
        p(root->right,v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        p(root,v);
        return v;
    }
};