// 540. Single Element in a Sorted Array
// Medium
// 8.3K
// 127
// Companies
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105
// Accepted
// 422.9K
// Submissions
// 716.7K
// Acceptance Rate
// 59.0%

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(),j = n-1,i=0;
        while(i<=j){
            int mid = (i+j)/2;
            int l = 1;
            if((mid-i)%2==0) l = 2;
            int m = 0;
            if(mid+1 < n && nums[mid] == nums[mid+1]) m = 1;
            else if(mid > 0 && nums[mid] == nums[mid-1]) m = -1;
            else return nums[mid];
            if(l == 2){
                if(m == 1){
                    i = mid+2;
                }
                else{
                    j = mid-2;
                }
            }
            else{
                if(m == 1){
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
        }
        return nums[n-1];
    }
};