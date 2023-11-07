class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> v;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};