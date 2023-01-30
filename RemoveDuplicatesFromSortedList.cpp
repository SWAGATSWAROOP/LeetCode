// 82. Remove Duplicates from Sorted List II
// Medium
// 7.2K
// 191
// Companies
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.
// Accepted
// 573.3K
// Submissions
// 1.3M
// Acceptance Rate
// 45.7%

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = 0;
        ListNode* next = head->next;
        while(curr){
            if(next && curr->val == next->val){
                while(next && curr->val == next->val){
                    ListNode* temp = next->next;
                    delete next;
                    next = temp;
                }
                if(!prev){
                    prev = 0;
                    head = next;
                }
                else{
                    prev->next = next;
                }
                delete curr;
                curr = 0;
                if(next && next->next){
                    curr = next;
                }
                if(curr && curr->next){
                    next = curr->next;
                }
            }
            else{
                prev = curr;
                curr = next;
                if(next) next = next->next;
            }
        }
        return head;
    }
};