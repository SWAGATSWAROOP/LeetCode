class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        while(i < nums.size() && (nums[i] & 1) == 0)i++;
        while(j >= 0 && (nums[j] & 1))j--;
        while(i < j){
            while(i < j && (nums[i] & 1) == 0)i++;
            while(j > i && (nums[j] & 1))j--;
            if(i < j)swap(nums[i],nums[j]);
            i++;
            j--;
        }
        return nums;
    }
};