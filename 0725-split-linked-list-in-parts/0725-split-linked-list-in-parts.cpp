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
    int co(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int c = co(head);
        if(c > k){
            while(k--){
                int f = ceil((1.0*c)/(k+1));
                ListNode* temp = head;
                int z = f;
                if(c >= f){
                    z -= 1;
                    while(z--)temp = temp->next;
                    ListNode* next = temp->next;
                    temp->next = 0;
                    v.push_back(head);
                    head = next;
                    c = c -f;
                }
                else{
                    z-= 2;
                    while(z--)temp = temp->next;
                    ListNode* next = 0;
                    if(temp){
                        next = temp->next;
                        temp->next = 0;
                    }
                    v.push_back(head);
                    head = next;
                    c = c - f + 1;
                }
            }
        }
        else{
            while(head){
                ListNode* next = head->next;
                head->next = 0;
                v.push_back(head);
                head = next;
            }
            while(v.size() < k)v.push_back(NULL);
        }
        return v;
    }
};