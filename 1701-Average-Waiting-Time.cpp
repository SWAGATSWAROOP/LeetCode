class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int sz = customers.size();
        double ans = 0;
        int start = customers[0][0];
        int end = 0;
        int diff;
        for(int i = 0;i < sz;i++){
            if(start < customers[i][0])start = customers[i][0];
            start += customers[i][1];
            diff = start - customers[i][0];
            if(diff <= 0)diff = customers[i][1]; 
            ans += diff;
        }
        ans = ans/sz;
        return ans;
    }
};