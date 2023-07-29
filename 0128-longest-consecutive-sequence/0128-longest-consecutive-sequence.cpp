class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i =0;i<nums.size();i++)s.insert(nums[i]);
        int count = 0;
        int mxC = 0;
        int prev = 0;
        for(auto x:s){
            if(x - prev > 1){
                mxC = max(count,mxC);
                count = 0;
            }
            prev = x;
            count++;
        }
        mxC = max(mxC,count);
        return mxC;
    }
};