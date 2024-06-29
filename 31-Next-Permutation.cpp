class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sw = 0,diff = INT_MAX,n = nums.size(),l = 0;
        for(int i = n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                sw = i-1;
                break;
            }
        }
        for(int i = sw+1;i<n;i++){
            int m = nums[i] - nums[sw];
            if(m>0 && diff>m)l = i;
        }
        if(sw==0 && l == 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        swap(nums[l],nums[sw]);
        reverse(nums.begin()+sw+1,nums.end());
    }
};