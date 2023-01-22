// 24. Swap Nodes in Pairs
// Medium
// 8.9K
// 349
// Companies
// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100
// Accepted
// 1M
// Submissions
// 1.7M
// Acceptance Rate
// 60.9%

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


#include<stack>
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == 0 || head->next == 0){
            return head;
        }
        stack<ListNode*> recurr;
        ListNode* temp = head;
        ListNode* next = 0;
        while(temp){
            recurr.push(temp);
            temp = temp->next;
        }
        if(recurr.size()%2!=0){
            next = recurr.top();
            recurr.pop();
        }
        while(!recurr.empty()){
            ListNode* temp1 = recurr.top();
            recurr.pop();
            ListNode* temp2 = recurr.top();
            recurr.pop();
            temp1->next = temp2;
            temp2->next = next;
            next = temp1;
        }
        return next;
    }
};