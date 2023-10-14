class Solution {
public:
    int mod = 1e9 + 7;
    long long binpow(long long a, long long b) {
        if(b < 0)return 0;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a)%mod;
            a = (a * a)%mod;
            b >>= 1;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++){
            int c = target - nums[i];
            if(c < 0)return count;
            count = (count+1)%mod;
            int index = upper_bound(nums.begin()+i,nums.end(),c) - nums.begin() - i;
            index--;
            int num = (binpow(2,index)%mod)-1;
            count = (count + num)%mod;
        }
        return count;
    }
};