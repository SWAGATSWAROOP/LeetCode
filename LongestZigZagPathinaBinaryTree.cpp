// 1372. Longest ZigZag Path in a Binary Tree
// Medium
// 2.6K
// 47
// Companies
// You are given the root of a binary tree.

// A ZigZag path for a binary tree is defined as follow:

// Choose any node in the binary tree and a direction (right or left).
// If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
// Change the direction from right to left or from left to right.
// Repeat the second and third steps until you can't move in the tree.
// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

// Return the longest ZigZag path contained in that tree.

 

// Example 1:


// Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
// Output: 3
// Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
// Example 2:


// Input: root = [1,1,1,null,1,null,null,1,1,null,1]
// Output: 4
// Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
// Example 3:

// Input: root = [1]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 5 * 104].
// 1 <= Node.val <= 100
// Accepted
// 88.3K
// Submissions
// 132.6K
// Acceptance Rate
// 66.6%

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
    int Z(TreeNode* root,int l,int& mx){
        if(!root)return 0;
        int m = Z(root->left,0,mx);
        int k = Z(root->right,1,mx);
        int x = max(m,k);
        mx  = max(x,mx);
        // cout<<x<<endl;
        if(l)return m+1;
        return k+1;
    }

    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
        int mx = INT_MIN;
        Z(root,0,mx);
        return mx;
    }
};