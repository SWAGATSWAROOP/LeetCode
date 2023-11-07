class Compare {
    public:
       bool operator()(pair<double,double> a,pair<double,double> b){
           double x = (1.0*a.first)/a.second;
           double y = (1.0*b.first)/b.second;
           return x >= y;
        }
};

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<pair<double,double>,vector<pair<double,double>>,Compare> pq;
        for(int i = 0;i < dist.size();i++){
            pq.push({dist[i],speed[i]});
        }
        double time = 0;
        int count = 0;
        while(!pq.empty()){
            double top = (pq.top().first/pq.top().second);
            double l = pq.top().first - time*pq.top().second;
            if(l < 1 && count)return count;
            time++;
            count++;
            cout<<pq.top().first<<" "<<pq.top().second<<endl;
            pq.pop();
        }
        return dist.size();
    }
};