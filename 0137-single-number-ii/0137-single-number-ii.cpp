class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(int i = 0;i<32;i++){
            int sum = 0;
            for(const auto j:nums)sum += j >> i & 1;
            sum %= 3;
            n |= sum << i;
        }
        return n;
    }
};