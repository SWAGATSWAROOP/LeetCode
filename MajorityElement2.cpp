// 229. Majority Element II
// Medium
// 6.8K
// 328
// Companies
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]
 

// Constraints:

// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109
 

// Follow up: Could you solve the problem in linear time and in O(1) space?

// Accepted
// 383.1K
// Submissions
// 853.3K
// Acceptance Rate
// 44.9%

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(),x = n/3,i = 0,j=0;
        sort(nums.begin(),nums.end());
        vector<int> v;
        while(j<n){
            while(j < n && nums[i]==nums[j]) j++;
            if(j-i > x) v.push_back(nums[i]);
            i = j;
        }
        return v;
    }
};