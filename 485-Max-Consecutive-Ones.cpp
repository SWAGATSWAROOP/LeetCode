class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0,n = nums.size(),tempcount = 0,i = 0;
        while(i < n){
            tempcount = 0;
            while((i < n) && (nums[i] == 1)){
                tempcount++;
                i++;
            }
            count = max(tempcount,count);
            while((i < n) && !nums[i])i++;
        }
        return count;
    }
};