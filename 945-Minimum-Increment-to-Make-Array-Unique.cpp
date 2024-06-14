class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = nums.size();
        sort(nums.begin(),nums.end());
        int count = 0,diff;
        for(int i = 1;i < n;i++){
            if(nums[i] <= nums[i-1]){
                diff  = abs(nums[i-1]-nums[i])+1;
                nums[i] += diff;
                count += diff;
            }
        }
        return count;
    }
};