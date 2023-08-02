const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1,0);
        prev[amount] = 1;
        for(int i = coins.size()-1;i>=0;i--){
            for(int j = amount-coins[i];j>=0;j--){
                int a = prev[j];
                int b = 0;
                if(j + coins[i] <= amount)b = prev[j+coins[i]];
                prev[j] = a+b;
            }
        }
        return prev[0];
    }
};