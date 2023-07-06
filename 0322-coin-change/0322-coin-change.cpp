const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1,1e5);
        prev[amount] = 0;
        for(int i = coins.size()-1;i>=0;i--){
            for(int j = amount;j>=0;j--){
                int k = 1e5;
                if(coins[i] <= amount && j+coins[i] <= amount)k = 1+prev[j+coins[i]];
                prev[j] = min(k,prev[j]);
            }
        }
        return prev[0] > 1e4 ? -1:prev[0];
    }
};