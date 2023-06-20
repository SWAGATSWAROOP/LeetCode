/*
Done Recursion didn'd add memo to it due to pair problem in unordered map.
 */
class Solution {
public:
    int rob1(TreeNode* root,int prev){
        if(!root)return 0;
        if(!prev){
            int l = rob1(root->left,0) + rob1(root->right,0);
            int k = root->val+rob1(root->left,1)+rob1(root->right,1);
            return max(k,l);
        }
        return rob1(root->left,0)+rob1(root->right,0);
    }

    int rob(TreeNode* root) {
        return rob1(root,0);
    }
};

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


//Memotization Sol
class Solution {
public:
    int rob1(TreeNode* root,unordered_map<TreeNode*, int>& m){
        if(!root)return 0;
        if(m.find(root) != m.end())return m[root];
        int k = root->val;
        if(root->left)k += rob1(root->left->left,m)+rob1(root->left->right,m);
        if(root->right)k += rob1(root->right->left,m)+rob1(root->right->right,m);
        int l = rob1(root->left,m)+rob1(root->right,m);
        m[root] = max(k,l);
        return m[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return rob1(root,m);
    }
};
