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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l = 0;
        ListNode* m = 0;
        ListNode* temp = head;
        ListNode* mt = 0;
        ListNode* lt = 0;
        while(temp){
            if(temp->val >= x){
                if(m)mt->next = temp;
                else m = temp;
                mt = temp;
            }
            else{
                if(l)lt->next = temp;
                else l = temp; 
                lt = temp;
            }
            temp = temp->next;
        }
        if(!l)return head;
        if(m)mt->next = 0;
        lt->next = m;
        return l;
    }
};