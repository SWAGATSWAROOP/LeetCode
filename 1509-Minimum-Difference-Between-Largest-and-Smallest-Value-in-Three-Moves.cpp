class Solution {
public:
    int minDifference(vector<int>& nums) {
        int size = nums.size();
        if(size <= 4)return 0;
        sort(nums.begin(),nums.end());
        int mindiff = INT_MAX;
        for(int i = 0,j = size  - 4;j < size;i++,j++){
            mindiff = min(mindiff,(nums[j] - nums[i]));
        }
        return mindiff;
    }
};