// 46. Permutations
// Medium
// 14.9K
// 254
// Companies
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.
// Accepted
// 1.5M
// Submissions
// 2M
// Acceptance Rate
// 75.5%

//Backtrackiing Solution
class Solution {
public:
    void insert(vector<vector<int>>& v,vector<int> v2,vector<int>& nums,int index,int size){
        if(index == size){
            v.push_back(v2);
            return;
        }
        int i = 0;
        for(int i = 0;i<=index;i++){
            v2.insert(v2.begin()+i,nums[index]);
            insert(v,v2,nums,index+1,size);
            v2.erase(v2.begin()+i);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        vector<int> v2;
        insert(v,v2,nums,0,n);
        return v;
    }
};