class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-2;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(!nums[i])continue;
            int k = i+2;
            for(int j = i+1;j<=n;j++){
                while(k<nums.size() && nums[i]+nums[j]>nums[k])k++;
                count += k - j - 1;
            }
        }
        return count;
    }
};