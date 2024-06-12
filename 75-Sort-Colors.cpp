class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0,n = nums.size(),j = n -1;
        while(j >=0 && nums[j] == 2)j--;
        while(i <= j && nums[i] == 0)i++;
        for(int k = i;k <= j;){
            if(nums[k] == 0){
                swap(nums[i],nums[k]);
                if(k == i)k++;
                i++;
            }
            else if(nums[k] == 2){
                swap(nums[j],nums[k]);
                j--;
            }
            else k++;
        }
    }
};