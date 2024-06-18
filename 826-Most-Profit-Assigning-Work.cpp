class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int dl = difficulty.size(),wl = worker.size();
        for(int i = 0;i < dl;i++)v.push_back({difficulty[i],profit[i]});
        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());
        priority_queue<int> pq;
        int i = 0,j = 0,sum = 0;
        while(i < wl && j < dl){
            while(j < dl && worker[i] >= v[j].first){
                pq.push(v[j].second);
                j++;
            }
            if(pq.size()){
                sum += pq.top();
            }
            i++;
        }
        if(pq.size() && wl != i)sum += (wl - i) * pq.top();
        return sum;
    }
};