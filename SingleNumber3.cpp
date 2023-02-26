// 260. Single Number III
// Medium
// 4.8K
// 208
// Companies
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]
 

// Constraints:

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.
// Accepted
// 289.6K
// Submissions
// 428.4K
// Acceptance Rate
// 67.6%


//Using HashMap Time Complexity = O(n) and Space Complexity = O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        vector<int> v;
        if(n <= 2) return nums;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(map.count(nums[i])>0) map.erase(nums[i]);
            else map[nums[i]] = nums[i];
        }
        for(auto i:map){
            v.push_back(i.second);
        }
        return v;
    }
};

//Using Sorting nlogn Space Complexity = O(2)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(),i = 0;
        vector<int> v;
        sort(nums.begin(),nums.end());
        while(i<n){
            if(i<n-1 && nums[i] == nums[i+1]) i+=2;
            else{
                v.push_back(nums[i]);
                i++;
            }
        }
        return v;
    }
};