class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = 0,n = profits.size();
        vector<pair<int,int>> v;
        for(int i = 0;i < n;i++)v.push_back({capital[i],profits[i]});
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        int j = 0;
        for(int i = 0;i < k;i++){
            while(j < n && v[j].first <= w){
                pq.push(v[j].second);
                j++;
            }

            if(pq.empty())break;

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};