
// Easy
// 9.4K
// 471
// Companies
// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced
//  binary search tree.

 

// Example 1:


// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:


// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in a strictly increasing order.
// Accepted
// 977.2K
// Submissions
// 1.4M
// Acceptance Rate
// 69.9%

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
    TreeNode* Array(vector<int> nums,int si,int ei){
        if(si > ei)return 0;
        int mid = (si+ei)/2;
        TreeNode* a = new TreeNode(nums[mid]);
        a->left = Array(nums,si,mid-1);
        a->right = Array(nums,mid+1,ei);
        return a; 
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Array(nums,0,nums.size()-1);
    }
};