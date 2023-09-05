/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
int c(Node* head,Node* r){
    int count = 0;
    while(head != r){
        count++;
        head = head->next;
    }
    return count;
}

class Solution {
public:
    Node* copyRandomList(Node* head1){
        if(!head1)return NULL;
        Node* temp = head1;
        temp = temp->next;
        Node* head2 = new Node(head1->val);
        Node* temp2 = head2;
        while(temp){
            temp2->next = new Node(temp->val);
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp2 = head2;
        temp = head1;
        while(temp2){
            int count = c(head1,temp->random);
            Node* temp3 = head2;
            while(count--)temp3 = temp3->next;
            temp2->random = temp3;
            temp2 = temp2->next;
            temp = temp->next;
        }
        return head2;
    }
};