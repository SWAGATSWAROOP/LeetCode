// Medium
// 4.2K
// 308
// Companies
// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
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
// 572.6K
// Submissions
// 935.4K
// Acceptance Rate
// 61.2%

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v2;
        if(!root)return v2;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size--){
                TreeNode* p = q.front();
                q.pop();
                v.push_back(p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            v2.insert(v2.begin(),v);
        }
        return v2;
    }
};