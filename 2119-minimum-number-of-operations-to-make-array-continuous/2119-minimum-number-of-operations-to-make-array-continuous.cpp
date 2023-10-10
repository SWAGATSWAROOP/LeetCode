class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> v;
        int ans = 1e6;
        for(int x:s)v.push_back(x);
        for(int i = 0;i<v.size();i++){
            int r = v[i] + nums.size() - 1;
            int j = upper_bound(v.begin(),v.end(),r)-v.begin();
            int k = nums.size() - j + i;
            ans = min(k,ans);
        }
        return ans;
    }
};