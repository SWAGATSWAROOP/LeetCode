class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int x:nums)map[x]++;
        int count = 0;
        for(auto x:map){
            if(x.second < 2)continue;
            else if(x.second == 2)count += 1;
            else if(x.second == 3)count += 3;
            else count += (x.second)*(x.second-1)/2;
        }
        return count;
    }
};