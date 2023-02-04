// 75. Sort Colors
// Medium
// 13.8K
// 499
// Companies
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// Accepted
// 1.3M
// Submissions
// 2.3M
// Acceptance Rate
// 58.0%


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0,blue = 0,n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i] == 0) red++;
            else if(nums[i]== 2) blue++;
        }
        for(int i = 0;i<red;i++){
            nums[i] = 0;
        }
        int j = n-1;
        for(;blue;j--){
            nums[j] = 2;
            blue--;
        }
        for(int i = red;i<=j;i++){
            nums[i] = 1;
        }
    }
};