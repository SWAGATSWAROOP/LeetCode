// Easy
// 4.5K
// 276
// Companies
// Given the root of a binary tree, return the sum of all left leaves.

// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
// Example 2:

// Input: root = [1]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -1000 <= Node.val <= 1000
// Accepted
// 433K
// Submissions
// 762.5K
// Acceptance Rate
// 56.8%

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
    int sumOfLeftLeaves(TreeNode* root,int s = 0) {
        if(!root->left && !root->right){
            if(s)return root->val;
            return 0;
        }
        int m = 0,n = 0;
        if(root->left)m = sumOfLeftLeaves(root->left,1);
        if(root->right)n = sumOfLeftLeaves(root->right,0);
        return m+n;
    }
};