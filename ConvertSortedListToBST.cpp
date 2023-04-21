// Medium
// 6.8K
// 147
// Companies
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
// height-balanced
//  binary search tree.

 

// Example 1:


// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105
// Accepted
// 473.2K
// Submissions
// 785.1K
// Acceptance Rate
// 60.3%
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sorted(ListNode* head,int length){
        if(!length)return 0;
        int mid = length/2;
        int k = mid;
        ListNode* temp = head;
        while(k--)temp = temp->next;
        TreeNode* root = new TreeNode(temp->val);
        root->left = sorted(head,mid);
        root->right = sorted(temp->next,length - mid - 1);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        return sorted(head,length);
    }
};