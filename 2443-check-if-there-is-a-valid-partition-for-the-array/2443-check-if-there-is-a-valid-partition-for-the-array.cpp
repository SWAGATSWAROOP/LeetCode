class Solution {
public:
    int VP(vector<int>& nums,int i,vector<int>& v){
        if(i == nums.size())return 1;
        if(v[i] != -1)return v[i];
        int m = 0,n = 0,k = 0; 
        if(i+1 < nums.size() && nums[i+1]==nums[i])m = VP(nums,i+2,v);
        if(i+2 < nums.size()){
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2])n = VP(nums,i+3,v);
            else if(nums[i+2]-nums[i] == 2 && nums[i+1] - nums[i]==1)k = VP(nums,i+3,v);
        }
        return v[i] = m || n || k;    
    }

    bool validPartition(vector<int>& nums) {
        vector<int> v(nums.size(),-1);
        return VP(nums,0,v);
    }
};