// 334. Increasing Triplet Subsequence
// Medium
// 6.3K
// 271
// Companies
// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

// Example 1:

// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.
// Example 2:

// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.
// Example 3:

// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

// Constraints:

// 1 <= nums.length <= 5 * 105
// -231 <= nums[i] <= 231 - 1
 

// Follow up: Could you implement a solution that runs in O(n) time complexity and O(1) space complexity?
// Accepted
// 376.4K
// Submissions
// 881K
// Acceptance Rate
// 42.7%

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int count = 0,n = nums.size(),curr = nums[0],currm = nums[0];
        for(int i=1;i<n;i++){
            if(currm<nums[i]){
                if(curr<nums[i]) count++;
                else count = 1;
                if(count == 2) return true;
                curr = nums[i];
            }
            else currm = min(currm,nums[i]);
        }
        return false;
    }
};