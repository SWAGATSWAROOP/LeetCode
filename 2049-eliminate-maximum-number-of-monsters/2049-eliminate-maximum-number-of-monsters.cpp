class Compare {
    public:
       bool operator()(pair<int,int> a,pair<int,int> b){
           double x = (1.0*a.first)/a.second;
           double y = (1.0*b.first)/b.second;
           return x >= y;
        }
};

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i = 0;i < dist.size();i++){
            pq.push({dist[i],speed[i]});
        }
        int time = 0;
        while(!pq.empty()){
            double l = pq.top().first - time*pq.top().second;
            if(l < 1)return time;
            time++;
            pq.pop();
        }
        return dist.size();
    }
};