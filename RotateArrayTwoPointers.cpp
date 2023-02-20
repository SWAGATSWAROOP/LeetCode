// 189. Rotate Array
// Medium
// 13.2K
// 1.5K
// Companies
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 

// Follow up:

// Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
// Could you do it in-place with O(1) extra space?
// Accepted
// 1.4M
// Submissions
// 3.6M
// Acceptance Rate
// 39.3%

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int m = nums.size();
        k %= m;
        int n = m-1-k,i = 0,j = n+1,z = m-1;
        while(i<n){
            swap(nums[i++],nums[n--]);
        }
        while(j<z){
            swap(nums[j++],nums[z--]);
        }
        i = 0, j = m-1;
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
    }
};

//Seen Solution
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int m = nums.size();
        reverse(nums.begin(),nums.end());
        k %= m;
        int i = 0,n = k-1,j = k,z = m-1; 
        while(i<n){
            swap(nums[i++],nums[n--]);
        }
        while(j<z){
            swap(nums[j++],nums[z--]);
        }
    }
};