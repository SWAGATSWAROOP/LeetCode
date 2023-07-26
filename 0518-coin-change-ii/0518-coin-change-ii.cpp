class Solution {
public:
int count(int amount,vector<int>& coins,int index,int sum,vector<vector<int>>& v){
        if(sum == amount)return 1;
        if(index == coins.size() || sum > amount)return 0;
        if(v[index][sum] != -1)return v[index][sum];
        int a = count(amount,coins,index+1,sum,v);
        int b = 0;
        if(sum + coins[index] <= amount)b = count(amount,coins,index,sum+coins[index],v);
        return v[index][sum] = a+b;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<int> prev(amount+1,0),curr(amount+1,0);
        prev[amount] = 1;
        for(int i = coins.size()-1;i>=0;i--){
            for(int j = amount;j>=0;j--){
                int a = prev[j];
                int b = 0;
                if(j + coins[i] <= amount)b = curr[j+coins[i]];
                curr[j] = a+b;
            }
            prev = curr;
        }
        return curr[0];
    }
};