// 35. Search Insert Position
// Easy
// 11.3K
// 522
// Companies
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0,j = nums.size()-1;
        if(target > nums[j]){
            return j+1;
        }
        if(target < nums[0]){
            return 0;
        }
        int s = 0;
        while(i<=j){
            int mid = (i+j)/2;
            s = mid;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        if(target < nums[s]){
            while(nums[s] > target){
                s--;
            }
            s += 1; //because the element should be inserted 1+curr index dry run
        }
        else{
            while(nums[s]<target){
                s++;
            }
        }
        return s;
    }
};