class Solution {
public:
    int C(vector<int>& nums,int i,int target,vector<unordered_map<int,int>>& v){
        if(!target)return 1;
        if(target < 0 || i == nums.size())return 0;
        if(v[i].count(target))return v[i][target];
        int a = C(nums,0,target-nums[i],v);
        int b = C(nums,i+1,target,v);
        return v[i][target] = a+b;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> v(nums.size());
        return C(nums,0,target,v);
    }
};