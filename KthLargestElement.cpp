// 215. Kth Largest Element in an Array
// Medium
// 13.5K
// 667
// Companies
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// You must solve it in O(n) time complexity.

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
 

// Constraints:

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104
// Accepted
// 1.7M
// Submissions
// 2.6M
// Acceptance Rate
// 66.1%

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