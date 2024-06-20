class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),sum = 0,l,count = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            l = sum - k;
            if(map.count(l))count += map[l];
            map[sum]++;
        }
        return count;
    }
};