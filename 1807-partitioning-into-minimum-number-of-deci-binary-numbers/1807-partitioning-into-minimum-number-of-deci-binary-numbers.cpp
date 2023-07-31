class Solution {
public:
    int minPartitions(string n) {
        int count = 0;
        int mx = 0;
        for(auto x:n){
            int l = x - '0';
            if(l > 0)mx = max(l,mx);
        }
        return mx;
    }
};