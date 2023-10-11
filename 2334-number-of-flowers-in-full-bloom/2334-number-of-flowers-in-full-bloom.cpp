class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,vector<int>& people) {
        vector<int> end;
        vector<int> start;
        for(int i = 0;i<flowers.size();i++){
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(end.begin(),end.end());
        sort(start.begin(),start.end());
        for(int i = 0;i<people.size();i++){
            int count = 0,mn = 0,mx = 0;
            mx = upper_bound(start.begin(),start.end(),people[i]) - start.begin();
            mn = lower_bound(end.begin(),end.end(),people[i]) - end.begin();
            people[i] = mx - mn;
        }
        return people;
    }
};