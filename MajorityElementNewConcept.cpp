// 169. Majority Element
// Easy
// 14K
// 433
// Companies
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -109 <= nums[i] <= 109
 

// Follow-up: Could you solve the problem in linear time and in O(1) space?
// Accepted
// 1.6M
// Submissions
// 2.6M
// Acceptance Rate
// 63.9%

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1,prev = nums[0],n = nums.size();
        for(int i = 1;i<n;i++){
            if(prev == nums[i])count++;   
            else if(prev != nums[i])count--;
            if(!count){
                count = 1;
                prev = nums[i];
            }
        }
        return prev;
    }
};