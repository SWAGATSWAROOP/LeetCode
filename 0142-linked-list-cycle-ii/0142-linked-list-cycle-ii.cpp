/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       unordered_map<ListNode*,bool> map;
       while(head){
           if(map.count(head))return head;
           map[head] = true;
           head = head->next;
       }
       return 0;
    }
};