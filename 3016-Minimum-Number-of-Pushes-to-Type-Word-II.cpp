class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        for(auto x:word){
            v[(x-'a')]++;
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int a = 0;
        for(int i = v.size()-1;i >= 0;i--){
            if(!v[i])break;
            if(a < 8)ans += v[i];
            else if(a < 16)ans += 2*v[i];
            else if(a < 24)ans += 3*v[i];
            else ans += 4*v[i];
            a++;
        }
        return ans;
    }
};