class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,n = nums.size();
        for(int j = 1;j < n;){
            while(j < n && nums[i] == nums[j])j++;
            if(j == n)return i+1;
            i++;
            nums[i] = nums[j];
        }
        return i+1;
    }
};