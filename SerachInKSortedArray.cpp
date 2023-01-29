// 33. Search in Rotated Sorted Array
// Medium
// 19.6K
// 1.2K
// Companies
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104
// Accepted
// 1.9M
// Submissions
// 4.9M
// Acceptance Rate
// 38.9%


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int J = nums.size()-1;
        int j = J;
        int l = J;
        int a = nums[0],b = nums[J];
        if(a == target || b == target){
            return a == target ? 0:J;
        }
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(mid == 0 || mid == J){
                l = mid == 0 ? 0:J-1;
                break;
            }
            else if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]){
                if(a > nums[mid]){
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }
            }
            else{
                l = nums[mid] > nums[mid+1] ? mid : mid - 1;
                break;
            }
        }
        if(nums[0] <= target && nums[l] >= target){
            i = 0;
        }
        else{
            i = l+1;
            l = J;
        }
        while(i<=l){
            int mid = (i+l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                l = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return -1;
    }
};