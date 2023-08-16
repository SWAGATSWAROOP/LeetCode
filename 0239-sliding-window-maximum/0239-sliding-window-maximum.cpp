class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1)return nums;
        multiset<int> s;
        vector<int> v;
        for(int l = 0;l<k;l++){
            s.insert(nums[l]);
        }
        multiset<int>::iterator itr = s.end();
        itr--;
        v.push_back(*itr);
        if(k == nums.size())return v;
        for(int i = 0,j = k;j<nums.size();i++,j++){
            auto it = s.find(nums[i]);
            s.erase(it);
            s.insert(nums[j]);
            multiset<int>::iterator itr = s.end();
            itr--;
            v.push_back(*itr);
        }
        return v;
    }
};