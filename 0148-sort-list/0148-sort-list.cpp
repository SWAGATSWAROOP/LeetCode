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
    ListNode* sortList(ListNode* head) {
        if(!head)return head;
        int len = 0;
        ListNode* temp;
        temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(len == 1)return head;
        int mid = len/2-1;
        temp = head;
        while(mid--)temp = temp->next;
        ListNode* next = temp->next;
        temp->next = 0;
        ListNode* l = sortList(head);
        ListNode* r = sortList(next);
        ListNode* k = 0;
        ListNode* y;
        while(l && r){
            if(l->val > r->val){
                if(k){
                    k->next = r;
                    k = k->next;
                }
                else{
                    k = r; 
                    y = r;
                } 
                r = r->next;
            }
            else{
                if(k){
                    k->next = l;
                    k = k->next;
                }
                else{
                    k = l; 
                    y = l;
                } 
                l = l->next;
            }
        }
        if(l)k->next = l;
        else if(r)k->next = r;
        return y;
    }
};