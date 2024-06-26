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
    void inorder(TreeNode* root,vector<int>& v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    TreeNode* balance(vector<int>& v,int s,int e){
        if(s > e)return 0;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(v[mid],balance(v,s,mid-1),balance(v,mid+1,e));
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int sz = v.size();
        return balance(v,0,sz-1);
    }
};