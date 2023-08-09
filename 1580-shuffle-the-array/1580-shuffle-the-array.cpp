class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> k;
        int i = 0,j = n;
        while(j < nums.size()){
            int z = j - i;
            if(z < n)k.push_back(nums[j++]);
            else k.push_back(nums[i++]);
        }
        return k;
    }
};