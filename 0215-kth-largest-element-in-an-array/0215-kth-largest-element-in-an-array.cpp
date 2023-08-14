class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k--;
        priority_queue<int> queue;
        for(auto x:nums)queue.push(x);
        while(k--)queue.pop();
        return queue.top();
    }
};