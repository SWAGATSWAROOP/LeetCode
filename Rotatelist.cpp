// 61. Rotate List
// Medium
// 7.2K
// 1.3K
// Companies
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109
// Accepted
// 685.9K
// Submissions
// 1.9M
// Acceptance Rate
// 36.0%

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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        ListNode* curr = head;
        int count = 0;
        while(curr){
            curr = curr->next;
            count++;
        }
        curr = head;
        k %= count; 
        ListNode* nav = head;
        while(nav->next && k){
            nav = nav->next;
            k--;
        }
        if(!nav->next && k) return head;
        while(nav->next){
            curr = curr->next;
            nav = nav->next;
        }
        nav->next = head;
        head = curr->next;
        curr->next = 0;
        return head;
    }
};