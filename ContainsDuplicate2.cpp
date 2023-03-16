// 219. Contains Duplicate II
// Easy
// 4.6K
// 2.5K
// Companies
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105
// Accepted
// 649.4K
// Submissions
// 1.5M
// Acceptance Rate
// 42.5%

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        map[nums[0]]++;
        for(int i=0,j=1;j<n;j++){
            if((j-i)>k){
                map.erase(nums[i]);
                i++;
            }
            if(map.count(nums[j])>0)return true;
            map[nums[j]]++;
        }
        return false;
    }
};