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
        vector<vector<int>> v(coins.size()+1,vector<int>(amount+1,1e5));
        v[coins.size()][amount] = 0;
        for(int i = coins.size()-1;i>=0;i--){
            for(int j = amount;j>=0;j--){
                int k = 1e5;
                if(coins[i] <= 1e4 && j+coins[i] <= amount)k = 1+v[i][j+coins[i]];
                v[i][j] = min(k,v[i+1][j]);
            }
        }
        return v[0][0] > 1e4 ? -1:v[0][0];
    }
};