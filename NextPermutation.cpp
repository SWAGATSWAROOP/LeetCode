// 31. Next Permutation
// Medium
// 14.7K
// 4.1K
// Companies
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
// Accepted
// 1M
// Submissions
// 2.7M
// Acceptance Rate
// 37.5%

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sw = 0,diff = INT_MAX,n = nums.size(),l = 0;
        for(int i = n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                sw = i-1;
                break;
            }
        }
        for(int i = sw+1;i<n;i++){
            int m = nums[i] - nums[sw];
            if(m>0 && diff>m)l = i;
        }
        if(sw==0 && l == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        swap(nums[l],nums[sw]);
        reverse(nums.begin()+sw+1,nums.end());
    }
};