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
    pair<int,int> avgS(TreeNode* root,int& count){
        if(!root)return make_pair(0,0);
        pair<int,int> left = avgS(root->left,count);
        pair<int,int> right = avgS(root->right,count);
        int c = left.second + right.second + 1;
        int sum = left.first + right.first + root->val;
        int SS = sum/c;
        if(SS == root->val)count++;
        return make_pair(sum,c);
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        avgS(root,count);
        return count;
    }
};