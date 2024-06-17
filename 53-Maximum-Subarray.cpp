class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxsum = nums[0],n = nums.size(),sum = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            mxsum = max(mxsum,sum);
            if(sum < 0)sum = 0;
        }
        return mxsum;
    }
};