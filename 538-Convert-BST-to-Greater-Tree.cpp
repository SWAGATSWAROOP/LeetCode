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
    int bst(TreeNode* root,int value){
        if(!root)return value;
        int right = bst(root->right,value);
        root->val += right;
        int left = bst(root->left,root->val);
        return left;
    }


    TreeNode* convertBST(TreeNode* root) {
        int value = 0;
        bst(root,value);
        return root;
    }
};