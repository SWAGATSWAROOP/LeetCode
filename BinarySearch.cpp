// 704. Binary Search
// Easy
// 7.9K
// 172
// Companies
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 

// Constraints:

// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.
// Accepted
// 1.5M
// Submissions
// 2.8M
// Acceptance Rate
// 55.3%

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] < target){
                i = mid+1;
            }
            else if(nums[mid] > target){
                j = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};