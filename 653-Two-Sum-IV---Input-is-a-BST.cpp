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

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        int i = 0,j = v.size()-1,sum;
        while(i < j){
            sum = v[i] + v[j];
            if(sum > k)j--;
            else if(sum < k)i++;
            else return true;
        }
        return false;
    }
};