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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head,*temp2 = head;
        while(temp2 && temp2->next){
            temp2 = temp2->next->next;
            temp = temp->next;
            if(temp == temp2)return true;
        }
        return false;
    }
};