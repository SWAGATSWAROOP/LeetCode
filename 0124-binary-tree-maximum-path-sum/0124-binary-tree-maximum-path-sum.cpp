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
const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int max_gain(TreeNode* root,int& res)
    {
        if(!root)return 0;
        int l = max_gain(root->left,res);
        int r = max_gain(root->right,res);
        int z = max(l,r);
        int temp = max(z+root->val,root->val);
        res = max(l+r+root->val,max(temp,res));
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = -1001;
        max_gain(root,res);
        return res;
    }
};