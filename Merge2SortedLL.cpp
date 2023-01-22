/**
 * 21. Merge Two Sorted Lists
Easy
16.8K
1.5K
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
Accepted
2.9M
Submissions
4.7M
Acceptance Rate
62.2%
 * 
 * 
 * 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == 0 || list2 == 0){
            return list1 == 0 ? list2 : list1;
        }
        ListNode* head = 0;
        ListNode* temp = 0;
        while(list1 && list2){
            ListNode* node = 0;
            if(list1->val > list2->val){
                node = new ListNode(list2->val);
                list2 = list2->next;
            }
            else{
                node = new ListNode(list1->val);
                list1 = list1->next;
            }
            if(!head){
                head = node;
                temp = head;
            }
            else{
                temp->next = node;
                temp = node;
            }
        }
        while(list1){
            temp->next = new ListNode(list1->val);
            list1 = list1->next;
            temp = temp->next;
        }
        while(list2){
            temp->next = new ListNode(list2->val);
            list2 = list2->next;
            temp = temp->next;
        }
        return head;
    }
};