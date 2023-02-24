// 137. Single Number II
// Medium
// 5.3K
// 538
// Companies
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each element in nums appears exactly three times except for one element which appears once.
// Accepted
// 399K
// Submissions
// 684.5K
// Acceptance Rate
// 58.3%


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int p = 0,q =0,n = nums.size();
        for(int i=0;i<n;i++){
            p = (p ^ nums[i]) & ~q;
            q = (q ^ nums[i]) & ~p;
        }
        return p;
    }
};