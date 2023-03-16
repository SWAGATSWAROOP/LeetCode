// 23. Merge k Sorted Lists
// Hard
// 16.6K
// 606
// Companies
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.
// Accepted
// 1.6M
// Submissions
// 3.2M
// Acceptance Rate
// 49.7%

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
    bool comp(ListNode*f,ListNode*s){
        return f->val < s->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode* head = lists[i];
            while(head){
                pq.push(head->val);
                head = head->next;
            }
        }
        if(pq.empty())return 0;
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = head;
        while(pq.size()){
            temp->next = new ListNode(pq.top());
            temp = temp->next;
            pq.pop();
        }
        return head;
    }
};