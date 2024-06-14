class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count0 = 0,n = nums.size(),ind = -1;
        for(int i = 0;i < n;i++){
            if(!nums[i]){
                count0++;
                if(ind == -1)ind = i;
            }
            else if(nums[i] && ind != -1){
                nums[ind] = nums[i];
                ind++;
            }
        }
        int i = n-1;
        while(count0--){
            nums[i] = 0;
            i--;
        }
    }
};