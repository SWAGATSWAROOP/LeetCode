// 47. Permutations II
// Medium
// 7.2K
// 128
// Companies
// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10
// Accepted
// 768.8K
// Submissions
// 1.3M
// Acceptance Rate
// 57.3%

class Solution {
public:
    void permute(vector<vector<int>>& v,vector<int>& nums,vector<int> v1,int index,int size){
        if(index == size){
            v.push_back(v1);
            return;
        }
        int n = v1.size();
        v1.insert(v1.begin(),nums[index]);
        permute(v,nums,v1,index+1,size);
        v1.erase(v1.begin());
        if(nums[index-1] != nums[index]){
            for(int i=1;i<n;i++){
                cout<<i<<endl;
                v1.insert(v1.begin()+i,nums[index]);
                permute(v,nums,v1,index+1,size);
                v1.erase(v1.begin()+i);
            }
            v1.push_back(nums[index]);
            permute(v,nums,v1,index+1,size);
        }
        else{
            for(int i = 1;i<n;i++){
                if(v1[i-1]==nums[index]){
                    break;
                }
                v1.insert(v1.begin()+i,nums[index]);
                permute(v,nums,v1,index+1,size);
                v1.erase(v1.begin()+i);
            }
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> v1;
        sort(nums.begin(),nums.end());
        v1.push_back(nums[0]);
        permute(v,nums,v1,1,nums.size());
        return v;
    }
};