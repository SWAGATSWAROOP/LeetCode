// 34. Find First and Last Position of Element in Sorted Array
// Medium
// 15.5K
// 366
// Companies
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109
// Accepted
// 1.4M
// Submissions
// 3.4M
// Acceptance Rate
// 41.7%


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        int i = 0;
        int j = nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                v[0] = mid;
                v[1] = mid;
                int l = mid - 1;
                while(l >= 0 && nums[l]==target){
                    v[0] = l--;
                }
                l = mid+1;
                while(l < nums.size() && nums[l] == target){
                    v[1] = l++;
                }
                return v;
            }
            else if(nums[mid] > target){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return v;
    }
};