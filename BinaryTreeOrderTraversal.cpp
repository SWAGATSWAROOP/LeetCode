// 102. Binary Tree Level Order Traversal
// Medium
// 12.8K
// 256
// Companies
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000
// Accepted
// 1.7M
// Submissions
// 2.7M
// Acceptance Rate
// 64.4%

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int> > v;
        if(!root)return v;
        while(!q.empty()){
            int l = q.size();
            vector<int> v1;
            while(l--){
                TreeNode* a = q.front();
                q.pop();
                v1.push_back(a->val);
                if(a->left)q.push(a->left);
                if(a->right)q.push(a->right);
            }
            v.push_back(v1);
        }
        return v;
    }
};