class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxprofit = 0,n = prices.size(),mn = 1e5,mx = -1;
        for(int i = 0;i < n;i++){
            if(mn > prices[i]){
                mn = prices[i];
                mx = prices[i];
            }
            else if(mx < prices[i]){
                mx = prices[i];
                mxprofit = max((mx-mn),mxprofit);
            }  
        }
        return mxprofit;
    }
};