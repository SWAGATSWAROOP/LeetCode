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
    void si(TreeNode* root,int& sum,int s){
        if(!root->left && !root->right){
            s = s*10+root->val;
            sum += s;
            return;
        }
        s = s*10+root->val;
        if(root->left)si(root->left,sum,s);
        if(root->right)si(root->right,sum,s);
        return;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        si(root,sum,0);
        return sum;
    }
};