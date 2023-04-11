// ver Binary Search Tree
// Medium
// 6.9K
// 224
// Companies
// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

// Example 1:


// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
// Example 2:


// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

// Constraints:

// The number of nodes in the tree is in the range [2, 1000].
// -231 <= Node.val <= 231 - 1
 

// Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
// Accepted
// 389.3K
// Submissions
// 762.8K
// Acceptance Rate
// 51.0%

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
    void recover(TreeNode* root,vector<int>& v){
        if(!root)return;
        recover(root->left,v);
        v.push_back(root->val);
        recover(root->right,v);
        return;
    }

    void recovery(TreeNode* root,vector<int>& v){
        if(!root)return;
        recovery(root->left,v);
        root->val = v[0];
        v.erase(v.begin());
        recovery(root->right,v);
        return;
    }

    void recoverTree(TreeNode* root) {
        vector<int> v;
        recover(root,v);
        sort(v.begin(),v.end());
        recovery(root,v);
    }
};