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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1 = new ListNode(head->next->val);
        ListNode* temp = head1;
        ListNode* temp2 = head->next->next;
        bool flag = false;
        while(temp2){
            if(temp2->val == 0)flag = true;
            else if(flag){
                temp->next = new ListNode(temp2->val);
                temp = temp->next;
                flag = false;
            }
            else temp->val += temp2->val;
            temp2 = temp2->next;
        }
        return head1;
    }
};