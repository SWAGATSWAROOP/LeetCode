class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int n = nums.size();
        for(int x:nums)set.insert(x);
        int y,count,mxcount = 0;
        for(int x:set){
            if(set.find(x-1) == set.end()){
                y = x+1;
                count = 1;
                while(set.find(y) != set.end()){
                    y++;
                    count++;
                }
                mxcount = max(count,mxcount);
            }
        }
        return mxcount;
    }
};