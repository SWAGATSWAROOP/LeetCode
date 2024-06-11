class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        map<int,int> map;
        for(auto x:arr1)map[x]++;
        for(auto x:arr2){
            while(map[x]--)v.push_back(x);
            map.erase(x);
        }
        for(auto x:map){
            while(x.second--)v.push_back(x.first);
        }
        return v;
    }
};