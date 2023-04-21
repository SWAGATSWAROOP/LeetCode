

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
    void preorder(TreeNode* root,vector<TreeNode*>& v){
        v.push_back(root);
        if(root->left)preorder(root->left,v);
        if(root->right)preorder(root->right,v);
        return;
    }

    void flatten(TreeNode* root) {
        if(!root)return;
        vector<TreeNode*> v;
        preorder(root,v);
        int n = v.size()-1;
        for(int i=0;i<n;i++){
            v[i]->left = 0;
            v[i]->right = v[i+1];
        }
        v[n]->right = 0;
    }
};