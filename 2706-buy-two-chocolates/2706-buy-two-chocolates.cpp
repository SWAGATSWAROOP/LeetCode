class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn1 = 101,mn2 = 101,n = prices.size();
        for(int i = 0;i<n;i++){
            if(prices[i] < mn1){
                mn2 = mn1;
                mn1 = prices[i];
            }
            else if(prices[i] < mn2)mn2 = prices[i];
        }
        int l = money - (mn1+mn2);
        if(l >= 0)return l;
        return money;
    }
};