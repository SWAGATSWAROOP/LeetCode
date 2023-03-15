// 40. Combination Sum II
// Medium
// 8.1K
// 202
// Companies
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30
// Accepted
// 718.7K
// Submissions
// 1.3M
// Acceptance Rate
// 53.4%

class Solution {
public:
    void cp(vector<vector<int>>& v,vector<int>& candidates,int target,vector<int> v2,int index,int size){
        if(target==0){
            v.push_back(v2);
            return;
        }
        else if(target < 0 || index == size) return;
        int i = 1;
        while(i <size-index && candidates[index+i] == candidates[index])i++;
        cp(v,candidates,target,v2,index+i,size);
        target -= candidates[index];
        v2.push_back(candidates[index]);
        cp(v,candidates,target,v2,index+1,size);
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> v2;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        cp(v2,candidates,target,v,0,n);
        return v2;
    }
};