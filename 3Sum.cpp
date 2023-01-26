// 15. 3Sum
// Medium
// 23.7K
// 2.2K
// Companies
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105
// Accepted
// 2.5M
// Submissions
// 7.6M
// Acceptance Rate
// 32.4%


#include<algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        if(nums[0] == nums[nums.size()-1]){
            if(nums[0] == 0){
                vector<int> v2(3,0);
                v.push_back(v2);
                return v;
            }
            return v;
        }
        int k = nums.size()-2;
        for(int i = 0;i<k;i++){
            if(nums[i] >= 1){
                return v;
            }
            if(i!=0 && nums[i] == nums[i-1]){
                continue;
            }
            int h = i+1;
            int j = k+1;
            while(h<j){
                int sum = nums[i]+ nums[h] + nums[j];
                if(sum == 0){
                    v.push_back({nums[i],nums[h],nums[j]});
                    int lastlow = nums[h];
                    int lasthigh = nums[j];
                    while(h<j && nums[h] == lastlow){
                        h++;
                    }
                    while(h<j && nums[j] == lasthigh){
                        j--;
                    }
                }
                else if(sum < 0){
                    h++;
                }
                else{
                    j--;
                }
            }
        }
        return v;
    }
};

