// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Medium
// 12.4K
// 361
// Companies
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.
// Accepted
// 939.8K
// Submissions
// 1.5M
// Acceptance Rate
// 61.5%

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
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int si,int ei,int pi,int pe){
        if(si > ei)return 0;
        TreeNode* root = new TreeNode(preorder[pi]);
        int i = si;
        for(;i<=ei;i++) if(preorder[pi]==inorder[i]) break;
        root->left = build(preorder,inorder,si,i-1,pi+1,pi+i-si);
        root->right = build(preorder,inorder,i+1,ei,pi+i-si+1,pe);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size()-1;
        return build(preorder,inorder,0,n,0,n);
    }
};