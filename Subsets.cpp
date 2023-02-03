Description
Discussion (22)
Solutions (7.2K)
Submissions
78. Subsets
Medium
13.5K
190
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
Accepted
1.4M
Submissions
1.8M
Acceptance Rate
74.5%

class Solution {
public:
    void sub(vector<vector<int>>& v,vector<int> v2,vector<int>& nums,int index){
        if(index == nums.size()){
            v.push_back(v2);
            return;
        }
        sub(v,v2,nums,index+1);
        v2.push_back(nums[index]);
        sub(v,v2,nums,index+1); 
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v2;
        sub(v,v2,nums,0);
        return v;
    }
};