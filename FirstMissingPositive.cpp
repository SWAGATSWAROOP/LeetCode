// 41. First Missing Positive
// Hard
// 13.5K
// 1.6K
// Companies
// Given an unsorted integer array nums, return the smallest missing positive integer.

// You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// Accepted
// 855.9K
// Submissions
// 2.3M
// Acceptance Rate
// 36.7%

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> map;
        for(auto x:nums)map.insert(x);
        for(int i = 1;i<=nums.size()+1;i++){
            if(map.count(i) == 0)return i;
        }
        return 1;
    }
};

//Small Version
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set <int> s(nums.begin(), nums.end());
        for(int i=1;;++i){
            if(!s.count(i))return i;
        }
    }
};