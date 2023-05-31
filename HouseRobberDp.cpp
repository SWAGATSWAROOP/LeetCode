// 8. House Robber
// Medium
// 17.8K
// 336
// Companies
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 400
// Accepted
// 1.6M
// Submissions
// 3.3M
// Acceptance Rate
// 49.6%

//Solved With Dp and Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return n == 1 ? nums[0]:max(nums[0],nums[1]);
        }
        int prev1 = nums[0],prev2 = nums[1];
        for(int i = 2;i<n;i++){
            int curr = nums[i] + max(prev2-nums[i-1],prev1);
            prev1 = prev2;
            prev2 = curr; 
        }
        return max(prev1,prev2);
    }
};