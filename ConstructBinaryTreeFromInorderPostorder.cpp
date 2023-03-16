// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Medium
// 6.4K
// 96
// Companies
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

// Example 1:
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.
// Accepted
// 491.6K
// Submissions
// 831.9K
// Acceptance Rate
// 59.1%
#include<iostream>
#include<vector>

//  * Definition for a binary tree node.
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int is,int ie,int ps,int pe){
        if(pe<ps) return 0;
        TreeNode* root = new TreeNode(postorder[pe]);
        int i = is;
        for(;i<=ie;i++){
            if(postorder[pe] == inorder[i])break;
        }
        // cout<<postorder[pe]<<" "<<endl;
        int endp = pe - (ie - i);
        root->right = build(inorder,postorder,i+1,ie,endp,pe-1);
        root->left = build(inorder,postorder,is,i-1,ps,endp-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size()-1;
        return build(inorder,postorder,0,n,0,n);
    }
};