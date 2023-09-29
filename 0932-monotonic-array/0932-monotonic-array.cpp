class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)return true;
        int k = 1;
        while(k < nums.size() && nums[k-1] == nums[k])k++;
        bool j = 1;
        if(k < nums.size() && nums[k-1] < nums[k])j = 0;
        for(int i = k+1;i<nums.size();i++){
            if(j && nums[i] > nums[i-1])return false;
            else if(!j && nums[i] < nums[i-1])return false;
        }
        return true;
    }
};