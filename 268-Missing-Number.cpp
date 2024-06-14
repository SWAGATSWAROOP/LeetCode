class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0,xor2 = 0,n = nums.size();
        for(int i = 0;i < n;i++){
            xor1 ^= nums[i];
            xor2 ^= i+1;
        }
        return xor1 ^ xor2;
    }
};