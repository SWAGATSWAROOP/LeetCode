class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int p = 0,q =0,n = nums.size();
        for(int i=0;i<n;i++){
            p = (p ^ nums[i]) & ~q;
            q = (q ^ nums[i]) & ~p;
        }
        return p;
    }
};