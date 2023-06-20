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
    pair<int,int> maxP(TreeNode* root){
        pair<int,int> rt = {root->val,1};
        bool lefti = false;
        if(root->left){
            pair<int,int> l = maxP(root->left);
            rt = rt.first < l.first ? make_pair(l.first,0):rt;
            if(l.second){
                int k = root->val + l.first;
                rt = rt.first <= k ? make_pair(k,1) : rt;
                lefti = true;
            }
        }
        if(root->right){
            pair<int,int> l = maxP(root->right);
            if(l.second && rt.second){
                int k = rt.first + l.first;
                rt = rt.first <= k ? make_pair(k,1) : rt;
            }
            rt = rt.first < l.first ? make_pair(l.first,0):rt;
        }
        return rt;
    }

    int maxPathSum(TreeNode* root) {
        return maxP(root).first;
    }
};

/*
124. Binary Tree Maximum Path Sum
Hard
14.4K
654
Companies
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000
Accepted
990.1K
Submissions
2.5M
Acceptance Rate
39.3%
*/
