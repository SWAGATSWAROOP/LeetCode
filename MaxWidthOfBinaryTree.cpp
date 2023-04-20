// . Maximum Width of Binary Tree
// Medium
// 7.2K
// 982
// Companies
// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

// Example 1:


// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
// Example 2:


// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
// Example 3:


// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).
 

// Constraints:

// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100
// Accepted
// 281.2K
// Submissions
// 665.9K
// Acceptance Rate
// 42.2%

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,long long> > pq;
        pair<TreeNode*,long long> p(root,0);
        pq.push(p);
        long long diff = 0;
        while(!pq.empty()){
            int size  = pq.size();
            diff = max(pq.back().second - pq.front().second,diff); 
            int mn = pq.front().second;
            while(size--){
                pair<TreeNode*,long long> s = pq.front();
                pq.pop();
                if(s.first->left){
                    pair<TreeNode*,long long> z(s.first->left,2*(s.second-mn));
                    pq.push(z);
                }
                if(s.first->right){
                    pair<TreeNode*,long long> z(s.first->right,2*(s.second-mn)+1);
                    pq.push(z);
                }
            }
        }
        return diff+1;
    }
};