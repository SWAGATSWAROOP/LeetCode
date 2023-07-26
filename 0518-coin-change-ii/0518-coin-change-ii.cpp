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
        vector<vector<int>> v(coins.size(),vector<int>(amount,-1));
        return count(amount,coins,0,0,v);
    }
};