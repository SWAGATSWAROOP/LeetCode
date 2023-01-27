// 98. Validate Binary Search Tree
// Medium
// 13.7K
// 1.1K
// Companies
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [2,1,3]
// Output: true
// Example 2:


// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1
// Accepted
// 1.8M
// Submissions
// 5.7M
// Acceptance Rate
// 31.9%
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
    bool Valid(TreeNode* root,long long mx,long long mn){
        if(!root){
            return true;
        }
        if((root->val == INT_MAX && root->right) || (root->val == INT_MIN && root->left) || root->val >= mx || root->val <= mn){
            return false;
        }
        return Valid(root->left,root->val,mn) && Valid(root->right,mx,root->val);
    }

    bool isValidBST(TreeNode* root) {
        return Valid(root,LLONG_MAX,LLONG_MIN);
    }
};

