// 94. Binary Tree Inorder Traversal
// Easy
// 10.7K
// 516
// Companies
// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?
// Accepted
// 1.9M
// Submissions
// 2.6M
// Acceptance Rate
// 73.5%

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
    void Traversal(TreeNode* root,vector<int> &v){
        if(!root->left){
            v.push_back(root->val);
            if(root->right){
                Traversal(root->right,v);
            }
            return;
        }
        if(root->left){
            Traversal(root->left,v);
        }
        v.push_back(root->val);
        if(root->right){
            Traversal(root->right,v);
        }
        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root){
            return v;
        }
        Traversal(root,v);
        return v;
    }
};