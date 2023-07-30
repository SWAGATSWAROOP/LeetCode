class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        int count = 0;
        for(int x:nums)s.insert(x);
        for(int i = 0;i<nums.size();i++){
            set<int> set;
            for(int j = i;j<nums.size();j++){
                set.insert(nums[j]);
                if(set == s)count++;
            }
        }
        return count;
    }
};