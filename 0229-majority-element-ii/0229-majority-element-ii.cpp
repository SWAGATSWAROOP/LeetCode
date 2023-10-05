class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(),x = n/3,i = 0,j=0;
        sort(nums.begin(),nums.end());
        vector<int> v;
        while(j<n){
            while(j < n && nums[i]==nums[j]) j++;
            if(j-i > x) v.push_back(nums[i]);
            i = j;
        }
        return v;
    }
};