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
    TreeNode* bst(vector<int>& arr,int mx,int mn,int& i,int n){
        if(i >= n || arr[i] >= mx || arr[i] <= mn)return NULL;
        TreeNode* root = new TreeNode(arr[i]);
        i++;
        root->left = bst(arr,root->val,mn,i,n);
        root->right = bst(arr,mx,root->val,i,n);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& arr) {
        int i = 0;
        return bst(arr,1001,0,i,arr.size());
    }
};