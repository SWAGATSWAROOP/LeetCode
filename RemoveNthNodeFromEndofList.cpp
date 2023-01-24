// 19. Remove Nth Node From End of List
// Medium
// 14.5K
// 599
// Companies
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 

// Follow up: Could you do this in one pass?

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n == 0){
            return head;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int count = 0;
        for(int i=0;i<=n;i++){
            if(temp2){
                temp2 = temp2->next;
                count++;
            }
            else if(count == n){
                head = temp1->next;
                delete temp1;
                return head;
            }
            else{
                return 0;
            }
        }
        while(temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ListNode* temp3 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp3;
        return head;
    }
};