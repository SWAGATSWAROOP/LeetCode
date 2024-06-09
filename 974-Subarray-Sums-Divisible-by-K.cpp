class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0,n = nums.size(),sum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            sum %= k;
            if(sum < 0){
                sum += k;
            }
            count += map[sum];
            map[sum]++;
        }
        return count;
    }
};