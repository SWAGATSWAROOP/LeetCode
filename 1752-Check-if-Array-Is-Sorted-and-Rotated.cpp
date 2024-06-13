class Solution {
public:
    bool check(vector<int>& nums) {
        int smindex = 0,sm = 101,n = nums.size();
        for(int i = 0;i < n;i++){
            if(sm > nums[i] || (sm == nums[i] && i && nums[i-1] != sm)){
                sm = nums[i];
                smindex = i;
            }
        }
        int i = smindex+1,prev = sm,curr;
        while((i%n) != smindex){
            curr = nums[(i%n)];
            if(prev > curr)return false;
            prev = curr;
            i++;
        }
        return true;
    }
};