class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = 1e6,sum = 0,index = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            while(sum >= target){
                length = min(length,i-index+1);
                sum -= nums[index++];
            }
        }
        return length = length == 1e6 ? 0:length;
    }
};