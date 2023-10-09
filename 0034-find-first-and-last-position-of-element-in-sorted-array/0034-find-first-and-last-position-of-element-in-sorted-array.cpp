class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(n == nums.size() || nums[n] != target)return {-1,-1};
        int z = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
        return {n,z};
    }
};