const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int possible(vector<int>& coins, int amount,int index,int sum,vector<vector<int>>& v){
        if(sum == amount)return 0;
        if(index == coins.size() || coins[index] >1e4)return 1e7;
        if(v[index][sum] != -1)return v[index][sum];
        int mn = 1e5;
        if(sum+coins[index] <= amount)mn = 1+possible(coins,amount,index,sum+coins[index],v); //Doing This error adding 1 before
        mn = min(mn,possible(coins,amount,index+1,sum,v));
        return v[index][sum] = mn;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> v(coins.size(),vector<int>(amount+1,-1));
        int l = possible(coins,amount,0,0,v);
        return l > 1e4 ? -1:l;
    }
};