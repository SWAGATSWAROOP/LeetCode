class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> v = {pref[0]};
        int n = pref.size()-1;
        for(int i = 0;i<n;i++){
            v.push_back(pref[i]^pref[i+1]);
        }
        return v;
    }
};