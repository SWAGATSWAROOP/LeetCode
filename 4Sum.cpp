// 18. 4Sum
// Medium
// 8.5K
// 990
// Companies
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Accepted
// 698.4K
// Submissions
// 1.9M
// Acceptance Rate
// 36.1%


//Better 89% beats in speed
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size() - 1;
        vector<vector<int>> v;
        if(n < 3 || nums[0]==nums[n]){
            if(1ll*nums[0]*4 == target && n>=3){
                v.push_back({nums[0],nums[0],nums[0],nums[0]});
            }
            return v;
        }
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            int target2 = target - nums[i];
            for(int j=i+1;j<n-1;j++){
                if(j!= i+1 && nums[j] == nums[j-1]) continue;
                long long target3 = 1ll*target2 - 1ll*nums[j];
                int k = j+1;
                int l = n;
                while(k<l){
                    long long sum = 1ll*nums[k]+1ll*nums[l];
                    if(sum == target3){
                        v.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int lastlow = nums[k];
                        int lasthigh = nums[l];
                        while(k<l && nums[k] == lastlow){
                            k++;
                        }
                        while(k<l && nums[l] == lasthigh){
                            l--;
                        }
                    }
                    else if(sum < target3){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return v;
    }
};

//beats 70% in runtime
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size() - 1;
        vector<vector<int>> v;
        if(n < 3 || nums[0]==nums[n]){
            if(1ll*nums[0]*4 == target && n>=3){
                v.push_back({nums[0],nums[0],nums[0],nums[0]});
            }
            return v;
        }
        for(int i=0;i<n-2;i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1;j<n-1;j++){
                if(j!= i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n;
                while(k<l){
                    long long sum = 1ll*nums[i]+1ll*nums[j]+1ll*nums[k]+1ll*nums[l];
                    if(sum == target){
                        v.push_back({nums[i],nums[j],nums[k],nums[l]});
                        int lastlow = nums[k];
                        int lasthigh = nums[l];
                        while(k<l && nums[k] == lastlow){
                            k++;
                        }
                        while(k<l && nums[l] == lasthigh){
                            l--;
                        }
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return v;
    }
};