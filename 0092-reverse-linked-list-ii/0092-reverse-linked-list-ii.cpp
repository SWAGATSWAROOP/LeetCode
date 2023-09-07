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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> st;
        ListNode* l = 0;
        ListNode* r = 0;
        ListNode* temp = head;
        while(right>=1){
            if(left<=1)st.push(temp);
            left--;
            right--;
            if(left == 1)l = temp;
            temp = temp->next;
        }
        r = temp;
        if(l){
            l->next = st.top();
            l = l->next;
        }
        else{
            l = st.top();
            head = l;
        }
        ListNode* tt = l;
        st.pop();
        while(!st.empty()){
            l->next = st.top();
            st.pop();
            l = l->next;
        }
        l->next = r;
        return head;
    }
};