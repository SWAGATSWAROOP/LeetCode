class Solution {
public:
    int bestClosingTime(string customers) {
        vector<pair<int,int>> v(customers.size()+1);
        v[0] = make_pair(0,0);
        int totalY = 0;
        for(int i = 1;i<=customers.size();i++){
            if(customers[i-1] == 'Y'){
                v[i] = make_pair(v[i-1].first+1,v[i-1].second);
                totalY++;
            }
            else v[i] = make_pair(v[i-1].first,v[i-1].second+1);
        }
        int penality = 1e5+1;
        int ans = 0;
        for(int i = 0;i<=customers.size();i++){
            int p = totalY - v[i].first + v[i].second;
            if(penality > p){
                penality = p;
                ans = i;
            }
        }
        return ans;
    }
};