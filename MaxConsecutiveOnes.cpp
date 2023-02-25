// 1004. Max Consecutive Ones III
// Medium
// 6K
// 69
// Companies
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length
// Accepted
// 280.9K
// Submissions
// 444K
// Acceptance Rate


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(),count = 0,i = 0,j = 0,l = k;
        while(j<n && i<n){
            if(nums[j]) j++;
            else if(l){
                l--;
                j++;
            }
            else if(!nums[i]){
                count = max(count,j-i);
                i++;
                j++;
            }
            else{
                i++;
                count = max(count,j-i+1);
            }
        }
        count = max(count,j-i);
        return count;
    }
};