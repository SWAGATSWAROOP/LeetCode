class Solution {
    public:
    int C(vector<int>& nums,int i,int target,vector<int>& v){
        if(!target)return 1;
        if(target < 0)return 0;
        if(v[target] != -1)return v[target];
        int ways = 0;
        for(int i = 0;i<nums.size();i++){
            ways += C(nums,i,target-nums[i],v);
        }
        return v[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> v(target+1,-1);
        return C(nums,0,target,v);
    }
};