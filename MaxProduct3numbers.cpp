// 628. Maximum Product of Three Numbers
// Easy
// 3.5K
// 586
// Companies
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 6
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:

// Input: nums = [-1,-2,-3]
// Output: -6
 

// Constraints:

// 3 <= nums.length <= 104
// -1000 <= nums[i] <= 1000
// Accepted
// 248.9K
// Submissions
// 538.9K
// Acceptance Rate
// 46.2%

#include<algorithm>
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int m = nums[0]*nums[1]*nums[nums.size()-1];
        int n = nums[nums.size()-3]*nums[nums.size()-2]*nums[nums.size()-1];
        return max(m,n);
    }
};