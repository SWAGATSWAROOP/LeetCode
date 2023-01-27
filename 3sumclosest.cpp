// 16. 3Sum Closest
// Medium
// 8.5K
// 464
// Companies
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

// Constraints:

// 3 <= nums.length <= 500
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
// Accepted
// 983.4K
// Submissions
// 2.1M
// Acceptance Rate
// 45.9%


#include<algorithm>
#include<climits>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 100000;
        int n = nums.size()-2;
        sort(nums.begin(),nums.end());
        if(nums[0] == nums[n+1]){
            return 3*nums[0];
        }
        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n+1;
            while(j<k){
                int s = nums[i]+nums[j]+nums[k];
                if(abs(target - sum) > abs(target-s)){
                    sum = s;
                }
                if(s == target){
                    return s;
                }
                else if(s > target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return sum;
    }
};