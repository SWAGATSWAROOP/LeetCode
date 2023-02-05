// 90. Subsets II
// Medium
// 7.5K
// 214
// Companies
// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// Accepted
// 659.2K
// Submissions
// 1.2M
// Acceptance Rate
// 55.7%

class Solution {
public:
    void subset(vector<vector<int>>& v,vector<int>& nums,vector<int> v2,int i,int n){
        if(i >= n){
            v.push_back(v2);
            return;
        }
        int count = 1;
        while(i+count<n && nums[i+count] == nums[i]) count++;
        subset(v,nums,v2,i+count,n);
        v2.push_back(nums[i]);
        subset(v,nums,v2,i+1,n);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        //v.push_back({});
        int n = nums.size();
        int i = 0;
        vector<int> v2;
        subset(v,nums,v2,0,n);
        // unordered_map<int,bool> map;
        // while(i<n){
        //     if(map.count(nums[i])>0){
        //         i++;
        //         continue;
        //     } 
        //     vector<int> v2;
        //     v2.push_back(nums[i]);
        //     map[nums[i]] = true;
        //     if(i+1 <= n) subset(v,nums,v2,i+1,n);
        //     i++;
        // }
        return v;
    }
};